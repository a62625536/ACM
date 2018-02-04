import urllib.parse
import urllib.request
import re
from bs4 import BeautifulSoup
from tkinter import *



# 中文空格填充
def myAlign(string, length=0):
    temp = 0
    for each in string:
        if each == 'A':
            temp += 1
    lens = length - 2*len(string) + temp
    for i in range(lens):
        string += ' '
    return string

def in_get():
    username = e1.get()
    password = e2.get()
    e1.delete(0,END)
    e2.delete(0,END)
    text1.insert(END,'学号:'+username+'\n\n')
    text1.insert(END,myAlign('科目',24))
    text1.insert(END,myAlign('学分',10))
    text1.insert(END,'分数\n\n')
    
    url = 'http://ids.xidian.edu.cn/authserver/login?service=http%3A%2F%2Fjwxt.xidian.edu.cn%2Fcaslogin.jsp'
    url2 = 'http://jwxt.xidian.edu.cn/gradeLnAllAction.do?type=ln&oper=qbinfo&lnxndm=2015-2016%E5%AD%A6%E5%B9%B4%E7%AC%AC%E4%BA%8C%E5%AD%A6%E6%9C%9F(%E4%B8%A4%E5%AD%A6%E6%9C%9F)#qb_2015-2016学年第二学期(两学期)'

    opener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor)
    text = opener.open(url).read().decode('utf-8')

    lt = re.findall(r'<input type="hidden" name="lt" value="(.+?)" />',text)[0]
    execution = re.findall(r'<input type="hidden" name="execution" value="(.+?)" />',text)[0]

    data = {}
    data['username'] = username
    data['password'] = password
    data['submit'] = ''
    data['lt'] = lt
    data['execution'] = execution
    data['_eventId'] = 'submit'

    data['rmShown'] = '1'
    data = urllib.parse.urlencode(data).encode('utf-8')
    
    req = opener.open(url,data)
    if req.url != r'http://jwxt.xidian.edu.cn/caslogin.jsp':
        text1.insert(END,'Error\n\n')
    
    response = opener.open(url2)
    soup = BeautifulSoup(response.read(),'html.parser')
    sum_score = 0
    sum_weight = 0
    print(soup)
    for each in soup('table',class_="titleTop2")[2](onmouseover="this.className='evenfocus';"):
        name = each()[2].string.strip()
        weight = each()[4].string.strip()
        score = each()[6].p.string.strip()
        text1.insert(END,myAlign(name,24))
        text1.insert(END,weight.ljust(10))
        text1.insert(END,'%s\n' % score)
        try:
            if float(score) <= 100 and each()[5].p.string.strip() != '¹«¹²ÈÎÑ':
                sum_score += float(score)*float(weight)
                sum_weight += float(weight)
        except:
            pass
    for each in soup('table',class_="titleTop2")[3](onmouseover="this.className='evenfocus';"):
        name = each()[2].string.strip()
        weight = each()[4].string.strip()
        score = each()[6].p.string.strip()
        text1.insert(END,myAlign(name,24))
        text1.insert(END,weight.ljust(10))
        text1.insert(END,'%s\n' % score)
        try:
            if float(score) <= 100:
                sum_score += float(score)*float(weight)
                sum_weight += float(weight)
        except:
            pass
    text1.insert(END,myAlign('\n所有含分数科目的均分：',26))
    ave = sum_score/sum_weight
    text1.insert(END,'%.2f\n\n' % ave)


root = Tk()
root.title('学生成绩查询')
Label(root,text = '学号',width = 10,justify = LEFT).grid(row = 0,column = 0)
Label(root,text = '密码',width = 10,justify = LEFT).grid(row = 1,column = 0)
e1 = Entry(root)
e1.grid(row = 0,column = 1)
e2 = Entry(root,show = '*')
e2.grid(row = 1,column = 1)
Label(root,text = '忽略了不及格成绩 -_-').grid(row = 2,column = 0,columnspan = 2)
Button(root,text = '查询',width = 10,command = in_get).grid(row = 3,column = 0,columnspan = 2)

frame = Frame(root,width = 40,height = 30)
frame.grid(row = 4,column = 0,columnspan = 2)

sb = Scrollbar(frame)
sb.pack(side = RIGHT,fill = Y)

text1 = Text(frame,width = 45,height = 20,yscrollcommand = sb.set)
text1.pack(side = LEFT,fill = BOTH)

sb.config(command = text1.yview)


mainloop()
    

        
