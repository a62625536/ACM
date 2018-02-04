import pygame
from pygame.locals import *
import sys
import traceback
import myplane
import enemy
import bullet
import supply
from random import *

# 初始化
pygame.init()
pygame.mixer.init()

bg_size = width,height = 480,700
screen = pygame.display.set_mode(bg_size)
pygame.display.set_caption('飞机大战')

background = pygame.image.load('images/background.png').convert_alpha()

# 载入音乐
pygame.mixer.music.load("sound/game_music.ogg")
pygame.mixer.music.set_volume(0.05)
bullet_sound = pygame.mixer.Sound("sound/bullet.wav")
bullet_sound.set_volume(0.05)
bomb_sound = pygame.mixer.Sound("sound/use_bomb.wav")
bomb_sound.set_volume(0.2)
supply_sound = pygame.mixer.Sound("sound/supply.wav")
supply_sound.set_volume(0.2)
get_bomb_sound = pygame.mixer.Sound("sound/get_bomb.wav")
get_bomb_sound.set_volume(0.2)
get_bullet_sound = pygame.mixer.Sound("sound/get_bullet.wav")
get_bullet_sound.set_volume(0.2)
upgrade_sound = pygame.mixer.Sound("sound/upgrade.wav")
upgrade_sound.set_volume(0.2)
enemy3_fly_sound = pygame.mixer.Sound("sound/enemy3_flying.wav")
enemy3_fly_sound.set_volume(0.2)
enemy1_down_sound = pygame.mixer.Sound("sound/enemy1_down.wav")
enemy1_down_sound.set_volume(0.1)
enemy2_down_sound = pygame.mixer.Sound("sound/enemy2_down.wav")
enemy2_down_sound.set_volume(0.2)
enemy3_down_sound = pygame.mixer.Sound("sound/enemy3_down.wav")
enemy3_down_sound.set_volume(0.5)
me_down_sound = pygame.mixer.Sound("sound/me_down.wav")
me_down_sound.set_volume(0.2)

# 定义颜色
BLACK = (0,0,0)
GREEN = (0,255,0)
RED = (255,0,0)
WHITE = (255,255,255)

# 添加飞机到组的函数
def add_small_enemies(group1,group2,num):
    for i in range(num):
        e = enemy.Smallenemy(bg_size)
        group1.add(e)
        group2.add(e)
def add_mid_enemies(group1,group2,num):
    for i in range(num):
        e = enemy.Midenemy(bg_size)
        group1.add(e)
        group2.add(e)
def add_big_enemies(group1,group2,num):
    for i in range(num):
        e = enemy.Bigenemy(bg_size)
        group1.add(e)
        group2.add(e)

# 敌方飞机加速的函数
def inc_speed(group,num):
    for each in group:
        each.speed += num


        
def main():
    pygame.mixer.music.play(-1)
    clock = pygame.time.Clock()
    
    
    # 生成我方飞机
    me = myplane.Myplane(bg_size)

    # 生成敌方飞机、放到组里
    enemies = pygame.sprite.Group()
    
    small_enemies = pygame.sprite.Group()
    add_small_enemies(small_enemies,enemies,15)
    mid_enemies = pygame.sprite.Group()
    add_mid_enemies(mid_enemies,enemies,4)
    big_enemies = pygame.sprite.Group()
    add_big_enemies(big_enemies,enemies,2)

    # 生成普通子弹
    bullet1 = []
    bullet1_index = 0
    for i in range(7):
        bullet1.append(bullet.Bullet1(me.rect.midtop))

    # 生成超级子弹
    bullet2 = []
    bullet2_index = 0
    for i in range(7):
        bullet2.append(bullet.Bullet2((me.rect.centerx-33,me.rect.centery)))
        bullet2.append(bullet.Bullet2((me.rect.centerx+33,me.rect.centery)))
        

    # 切换飞机图片
    switch = 1

    # 用以延迟以切换飞机
    delay = 5

    # 中弹图片索引
    big_destroy_index = 0
    mid_destroy_index = 0
    small_destroy_index = 0
    me_destroy_index = 0

    # 统计得分
    score = 0

    # 字体
    score_font = pygame.font.Font('font/font.ttf',36)

    # 标志是否暂停
    pause = False
    pause_nor_image = pygame.image.load('images/pause_nor.png').convert_alpha()
    pause_pressed_image = pygame.image.load('images/pause_pressed.png').convert_alpha()
    resume_nor_image = pygame.image.load('images/resume_nor.png').convert_alpha()
    resume_pressed_image = pygame.image.load('images/resume_pressed.png').convert_alpha()
    pause_rect = pause_nor_image.get_rect()
    pause_rect.left,pause_rect.top = width - pause_rect.width - 10,10
    pause_image = pause_nor_image

    # 设置难度级别
    level = 1

    # 全屏炸弹
    bomb_image = pygame.image.load('images/bomb.png').convert_alpha()
    bomb_rect = bomb_image.get_rect()
    bomb_font = pygame.font.Font('font/font.ttf',48)
    bomb_num = 3

    # 每30秒发放补给包
    bullet_supply = supply.Bulletsupply(bg_size)
    bomb_supply = supply.Bombsupply(bg_size)
    SUPPLY = USEREVENT
    pygame.time.set_timer(SUPPLY,30*1000)

    # 超级子弹定时器
    DOUBLE = USEREVENT + 1

    # 标志是否使用超级子弹
    isdouble = False

    # 飞机生命
    life_image = pygame.image.load('images/life.png').convert_alpha()
    life_rect = life_image.get_rect()
    life_num = 3

    # 解除无敌定时器
    UNWUDI = USEREVENT +2

    # 记录是否更新记录
    recorded = False

    # 游戏结束相关
    gameover_font = pygame.font.Font('font/font.ttf',48)
    again_image = pygame.image.load('images/again.png').convert_alpha()
    again_rect = again_image.get_rect()
    gameover_image = pygame.image.load('images/gameover.png').convert_alpha()
    gameover_rect = gameover_image.get_rect()

    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.mixer.music.stop()
                pygame.quit
                sys.exit()

            # 检测鼠标
            elif event.type == MOUSEBUTTONDOWN:
                if event.button == 1 and pause_rect.collidepoint(event.pos):
                    pause = not pause
                    if pause:
                        pause_image = resume_pressed_image
                        pygame.time.set_timer(SUPPLY,0)
                        pygame.mixer.music.pause()
                        pygame.mixer.pause()
                    else:
                        pause_image = pause_pressed_image
                        pygame.time.set_timer(SUPPLY,30*1000)
                        pygame.mixer.music.unpause()
                        pygame.mixer.unpause()
                        

            elif event.type == MOUSEMOTION:
                if pause_rect.collidepoint(event.pos):
                    if pause:
                        pause_image = resume_pressed_image
                        
                    else:
                        pause_image = pause_pressed_image
                        
                else:
                    if pause:
                        pause_image = resume_nor_image
                    else:
                        pause_image = pause_nor_image

            # 检测炸弹引爆    
            elif event.type ==  KEYDOWN:
                if event.key == K_SPACE:
                    if bomb_num:
                        bomb_num -= 1
                        bomb_sound.play()
                        for each in enemies:
                            if each.rect.bottom > 0:
                                each.active = False

            # 关闭计时器
            elif event.type == DOUBLE:
                isdouble = False
                pygame.time.set_timer(DOUBLE,0)

            # 发放补给
            elif event.type == SUPPLY:
                supply_sound.play()
                if choice([1,0]):
                    bomb_supply.reset()
                else:
                    bullet_supply.reset()
            elif event.type== UNWUDI:
                me.invincible = False
                pygame.time.set_timer(UNWUDI,0)

        # 根据分数改变难度
        if level == 1 and score > 50000:
            level = 2
            
            upgrade_sound.play()
            
            add_small_enemies(small_enemies,enemies,3)
            add_mid_enemies(mid_enemies,enemies,2)
            add_big_enemies(big_enemies,enemies,1)
            inc_speed(small_enemies,1)

        elif level ==2 and score > 300000:
            level = 3

            upgrade_sound.play()
            
            add_small_enemies(small_enemies,enemies,5)
            add_mid_enemies(mid_enemies,enemies,3)
            add_big_enemies(big_enemies,enemies,2)
            inc_speed(small_enemies,1)
            inc_speed(mid_enemies,1)

        elif level ==3 and score > 600000:
            level = 4

            upgrade_sound.play()
            
            add_small_enemies(small_enemies,enemies,5)
            add_mid_enemies(mid_enemies,enemies,3)
            add_big_enemies(big_enemies,enemies,2)
            inc_speed(small_enemies,1)
            inc_speed(mid_enemies,1)

        elif level ==4 and score > 1000000:
            level = 5

            upgrade_sound.play()
            
            add_small_enemies(small_enemies,enemies,5)
            add_mid_enemies(mid_enemies,enemies,3)
            add_big_enemies(big_enemies,enemies,2)
            inc_speed(small_enemies,1)
            inc_speed(mid_enemies,1)
            inc_speed(big_enemies,1)
            
        # 加载背景
        screen.blit(background,(0,0))

        
        if life_num and not pause:
            # 检测键盘操作
            key_pressed = pygame.key.get_pressed()

            if key_pressed[K_w] or key_pressed[K_UP]:
                me.moveUp()
            if key_pressed[K_s] or key_pressed[K_DOWN]:
                me.moveDown()
            if key_pressed[K_a] or key_pressed[K_LEFT]:
                me.moveLeft()
            if key_pressed[K_d] or key_pressed[K_RIGHT]:
                me.moveRight()

            # 是否加载补给
            if bomb_supply.active:
                bomb_supply.move()
                screen.blit(bomb_supply.image,bomb_supply.rect)
                if pygame.sprite.collide_mask(bomb_supply,me):
                    get_bomb_sound.play()
                    if bomb_num < 3:
                        bomb_num += 1
                    bomb_supply.active = False

            if bullet_supply.active:
                bullet_supply.move()
                screen.blit(bullet_supply.image,bullet_supply.rect)
                if pygame.sprite.collide_mask(bullet_supply,me):
                    get_bullet_sound.play()
                    pygame.time.set_timer(DOUBLE,18*1000)
                    isdouble = True
                    bullet_supply.active = False

            # 检测我方飞机碰撞
            enemies_down = pygame.sprite.spritecollide(me,enemies,False,pygame.sprite.collide_mask)
            if enemies_down and not me.invincible:
                me.active = False
                for e in enemies_down:
                    e.active = False
            # 加载我方飞机(活)
            if me.active:
                if switch:
                    screen.blit(me.image1,me.rect)
                else:
                    screen.blit(me.image2,me.rect)

            # 加载我方飞机(死)
            else:
                if delay == 5:
                    if me_destroy_index == 0:
                        me_down_sound.play()
                    screen.blit(me.destroy_images[me_destroy_index],me.rect)
                    me_destroy_index  = (me_destroy_index+1)%4
                    if me_destroy_index == 0:
                        life_num -= 1
                        me.reset()
                        pygame.time.set_timer(UNWUDI,3000)
                        

            # 发射子弹
            if delay == 5:
                bullet_sound.play()
                if isdouble:
                    bullets = bullet2
                    bullets[bullet2_index].reset((me.rect.centerx-33,me.rect.centery))
                    bullets[bullet2_index+1].reset((me.rect.centerx+30,me.rect.centery))
                    bullet2_index  = (bullet2_index+2)%14
                else:
                    bullets = bullet1
                    bullets[bullet1_index].reset(me.rect.midtop)
                    bullet1_index  = (bullet1_index+1)%7

            # 检测子弹碰撞
            for b in bullets:
                if b.active:
                    b.move()
                    screen.blit(b.image,b.rect)
                    enemy_hit = pygame.sprite.spritecollide(b,enemies,False,pygame.sprite.collide_mask)
                    if enemy_hit:
                        b.active = False
                        for e in enemy_hit:
                            
                            # 中大敌机被击中
                            if e in mid_enemies or e in big_enemies:
                                e.hit = 1
                                e.energy -= 1
                                if e.energy == 0:
                                    e.active = False

                            # 小飞机被击中
                            else:
                                e.active = False
                
                
            

            # 绘制敌方飞机
            for each in big_enemies:

                # 若存活
                if each.active:
                    each.move()

                    # 被打到事
                    if each.hit:
                        screen.blit(each.image_hit,each.rect)
                        each.hit = 0
                    elif switch:
                        screen.blit(each.image1,each.rect)
                    else:
                        screen.blit(each.image2,each.rect)

                    # 绘制血槽
                    pygame.draw.line(screen,BLACK,\
                                     (each.rect.left,each.rect.top -5),\
                                     (each.rect.right,each.rect.top -5),\
                                     2)
                    # 生命大于 20% 绿色，否则红色

                    energy_remain = each.energy/enemy.Bigenemy.energy
                    if energy_remain > 0.2:
                        energy_color = GREEN
                    else:
                        energy_color = RED
                    pygame.draw.line(screen,energy_color,\
                                     (each.rect.left,each.rect.top -5),\
                                     (each.rect.left+each.rect.width*energy_remain,each.rect.top -5),\
                                     2)

                    # 敌方大飞机即将出现时，音效
                    if each.rect.bottom == -50:
                        enemy3_fly_sound.play(-1)

                # 若死亡
                else:
                    if delay == 5:
                        if big_destroy_index == 0:
                            enemy3_down_sound.play()
                        screen.blit(each.destroy_images[big_destroy_index],each.rect)
                        big_destroy_index  = (big_destroy_index+1)%6
                        if big_destroy_index == 0:
                            enemy3_fly_sound.stop()
                            score += 10000
                            each.reset()
                    
                    
            for each in mid_enemies:
                if each.active:
                    each.move()
                    if each.hit:
                        screen.blit(each.image_hit,each.rect)
                        each.hit = 0
                    else:
                        screen.blit(each.image,each.rect)

                    # 绘制血槽
                    pygame.draw.line(screen,BLACK,\
                                     (each.rect.left,each.rect.top -5),\
                                     (each.rect.right,each.rect.top -5),\
                                     2)
                    # 生命大于 20% 绿色，否则红色

                    energy_remain = each.energy/enemy.Midenemy.energy
                    if energy_remain > 0.2:
                        energy_color = GREEN
                    else:
                        energy_color = RED
                    pygame.draw.line(screen,energy_color,\
                                     (each.rect.left,each.rect.top -5),\
                                     (each.rect.left+each.rect.width*energy_remain,each.rect.top -5),\
                                     2)
                else:
                    if delay == 5:
                        if mid_destroy_index == 0:
                            enemy2_down_sound.play()
                        screen.blit(each.destroy_images[mid_destroy_index],each.rect)
                        mid_destroy_index  = (mid_destroy_index+1)%4
                        if mid_destroy_index == 0:
                            score += 6000
                            each.reset()
                    
            for each in small_enemies:
                if each.active:
                    each.move()
                    screen.blit(each.image,each.rect)
                else:
                    if delay == 5:
                        if small_destroy_index == 0:
                            enemy1_down_sound.play()
                        screen.blit(each.destroy_images[small_destroy_index],each.rect)
                        small_destroy_index  = (small_destroy_index+1)%4
                        if small_destroy_index == 0:
                            score += 1000
                            each.reset()
            
            # 加载分数
            score_text = score_font.render('Score : %s' % str(score),True,WHITE)
            screen.blit(score_text,(10,5))

            # 加载炸弹数量
            bomb_text = bomb_font.render('x %d' % bomb_num,True,WHITE)
            bombtext_rect = bomb_text.get_rect()
            screen.blit(bomb_image,(10,height-10-bomb_rect.height))
            screen.blit(bomb_text,(20+bomb_rect.width,height - 5 - bombtext_rect.height))

            # 加载生命数量
            life_text = bomb_font.render('x %d' % life_num,True,WHITE)
            lifetext_rect = life_text.get_rect()
            screen.blit(life_image,(300,height-10-life_rect.height))
            screen.blit(life_text,(310+life_rect.width,height - 5 - lifetext_rect.height))

        elif life_num ==0:
            
            if not recorded:
                recorded = True

                # 停止补给
                pygame.time.set_timer(SUPPLY,0)
            
                # 音乐音效停止
                pygame.mixer.music.stop()
                pygame.mixer.stop()

                # 更新最高分
                with open('record.txt','r') as f:
                    record = int(f.read())
                if score > record:
                    with open('record.txt','w') as f:
                        f.write(str(score))

            with open('record.txt','r') as f:
                    record = int(f.read())
            # 加载结束画面
            record_score_text = score_font.render("Best : %d" % record, True, (255, 255, 255))
            screen.blit(record_score_text, (50, 50))
            
            gameover_text1 = gameover_font.render("Your Score", True, (255, 255, 255))
            gameover_text1_rect = gameover_text1.get_rect()
            gameover_text1_rect.left, gameover_text1_rect.top = \
                                 (width - gameover_text1_rect.width) // 2, height // 3
            screen.blit(gameover_text1, gameover_text1_rect)
            
            gameover_text2 = gameover_font.render(str(score), True, (255, 255, 255))
            gameover_text2_rect = gameover_text2.get_rect()
            gameover_text2_rect.left, gameover_text2_rect.top = \
                                 (width - gameover_text2_rect.width) // 2, \
                                 gameover_text1_rect.bottom + 10
            screen.blit(gameover_text2, gameover_text2_rect)

            again_rect.left, again_rect.top = \
                             (width - again_rect.width) // 2, \
                             gameover_text2_rect.bottom + 50
            screen.blit(again_image, again_rect)

            gameover_rect.left, gameover_rect.top = \
                                (width - again_rect.width) // 2, \
                                again_rect.bottom + 10
            screen.blit(gameover_image, gameover_rect)

            # 检测用户的鼠标操作
            # 如果用户按下鼠标左键
            if pygame.mouse.get_pressed()[0]:
                # 获取鼠标坐标
                pos = pygame.mouse.get_pos()
                # 如果用户点击“重新开始”
                if again_rect.left < pos[0] < again_rect.right and \
                   again_rect.top < pos[1] < again_rect.bottom:
                    # 调用main函数，重新开始游戏
                    main()
                # 如果用户点击“结束游戏”            
                elif gameover_rect.left < pos[0] < gameover_rect.right and \
                     gameover_rect.top < pos[1] < gameover_rect.bottom:
                    # 退出游戏
                    pygame.quit()
                    sys.exit()      

        # 加载暂停按钮
        screen.blit(pause_image,pause_rect)
            
        # 飞机的切换
        delay -= 1
        if delay == 0:
            switch = not switch
            delay =5

        # 刷新界面
        pygame.display.flip()
            
        # 最大帧率60
        clock.tick(60)



if __name__ == "__main__":
    try:
        main()
    except SystemExit:
        pass
    except:
        traceback.print_exc()
        pygame.quit()
        input()
