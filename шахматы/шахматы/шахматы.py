from openpyxl import workbook
from openpyxl import Workbook
import wget
url=input("Введите ссылку на игру: ")
if "white" in url:
    url=url[:url.index('white')-1]
if "black" in url:
    url=url[:url.index('black')-1]
link=url[url.index('/',10)+1::]
url='https://lichess.org/game/export/'+link+'?evals=0&clocks=0'

wget.download(url, link+'.txt')
s=list(map(str, open(link+'.txt')))

wb = Workbook()
sheet=wb.active
game=['/']*122
date=s[2][s[2].index('"')+1:]
date=date[:date.index('"')]
date=date[-2]+date[-1]+'.'+date[-5]+date[-4]+'.'+date[:4]
game_local=s[-3].split(' ')


game_local=[a for a in game_local if int(a[0],36)>=10]
for i in range(len(game_local)):
    game[i]=game_local[i]

flag=True;
for i in range(32):
    sheet.cell(row=14+i, column=3).value=game[i*2]
    sheet.cell(row=14+i, column=4).value=game[i*2+1]
    if i==31: break
else:
    flag=False;
if flag:
    for i in range(32, 61):
        sheet.cell(row=i-18, column=6).value=game[i*2]
        sheet.cell(row=i-18, column=7).value=game[i*2+1]



sheet.merge_cells('B1:S1')



from openpyxl.styles import Font, Alignment
from openpyxl.utils.cell import get_column_letter
fontStyle = Font(size = "14", bold=True)
sheet.cell(row = 1, column = 2, value = 'Отчет о результатах самостоятельной работы обучающегося по дисциплинам \n "Физическая культура" или "Элективные курсы по физической культуре и спорту" ').font = fontStyle
sheet['B1'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True) 
sheet.row_dimensions[1].height = 40

sheet.merge_cells('N3:S4')

fontStyle = Font(size = "10", bold=True, color="2E75B6")
sheet.cell(row = 3, column = 14, value ='Формат имени файла с отчетом: Отчет.ТК.ФВиС.999901.2020-04-12, где ТК – текущий контроль, ФВиС – кафедра физического воспитания и спорта, 999901 – номер студ. билета, 2020-04-12 – дата отправки отчета.').font = fontStyle
sheet['N3'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True) 
sheet.row_dimensions[3].height = 40; sheet.row_dimensions[4].height = 40;

for i in range(14, 46):
    c=i-13
    cur="B"+str(i)
    sheet.cell(row=i,column=2,value=c).font=fontStyle
    sheet[cur].alignment = Alignment(horizontal="center", vertical="center")
for i in range(14, 42):
    c=i+19
    cur="E"+str(i)
    sheet.cell(row=i,column=5,value=c).font=fontStyle
    sheet[cur].alignment = Alignment(horizontal="center", vertical="center")

for i in range(14, 46):
    c=i-13
    cur="H"+str(i)
    sheet.cell(row=i,column=8,value=c).font=fontStyle
    sheet[cur].alignment = Alignment(horizontal="center", vertical="center")
for i in range(14, 42):
    c=i+19
    cur="K"+str(i)
    sheet.cell(row=i,column=11,value=c).font=fontStyle
    sheet[cur].alignment = Alignment(horizontal="center", vertical="center")
from openpyxl.styles.borders import Border, Side
from openpyxl import Workbook

thin_border = Border(left=Side(style='thin'), 
                     right=Side(style='thin'), 
                     top=Side(style='thin'),
                     bottom=Side(style='thin'))
bold_right=Border(right=Side(style='medium'))
bold_right_up=Border(right=Side(style='medium'),top=Side(style='thin'), bottom=Side(style='thin'))
bold_down=Border(bottom=Side(style='medium'))
bold_up=Border(top=Side("medium"))
for y in range(14,46):
    for x in range(1,13):
        sheet.cell(row=y, column=x).border = thin_border
    sheet.cell(row=y, column=1).border = bold_right
    sheet.cell(row=y, column=4).border = bold_right_up
    sheet.cell(row=y, column=2).border = bold_right
    sheet.cell(row=y, column=5).border = bold_right
    sheet.cell(row=y, column=8).border = bold_right
    sheet.cell(row=y, column=7).border = bold_right_up
    sheet.cell(row=y, column=10).border = bold_right_up
    sheet.cell(row=y, column=11).border = bold_right
    sheet.cell(row=y, column=13).border = bold_right_up

    for x in range(2, 14):
        sheet.cell(row=2, column=x).border = bold_down
        sheet.cell(row=13, column=x).border = bold_down
        sheet.cell(row=46, column=x).border = bold_up
        sheet.cell(row=5, column=x).border = bold_up
        

up_r_l=Border(right=Side(style='thin'),left=Side(style='thin'),top=Side(style='medium'))
left=Border(left=Side(style='thin'))
sheet.merge_cells('C3:F3')
sheet.merge_cells('H3:J3')
sheet.merge_cells('K3:M3')

sheet.merge_cells('C4:F4')
sheet.merge_cells('H4:J4')
sheet.merge_cells('K4:M4')

sheet.cell(row=3,column=2).border=up_r_l
sheet.cell(row=3,column=14).border=left
sheet.cell(row=4,column=14).border=left
sheet.cell(row=3, column=2,value="Студ.\nбилет: ").font=Font(size='11', bold=True)
sheet['B3'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True) 

sheet.cell(row=3,column=3).border=up_r_l
sheet.cell(row=3, column=3,value="ФИО ").font=Font(size='11', bold=True)
sheet['C3'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True) 


sheet.cell(row=3,column=7).border=up_r_l
sheet.cell(row=3, column=7,value="Группа ").font=Font(size='11', bold=True)
sheet['G3'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True) 

sheet.cell(row=3,column=8).border=up_r_l
sheet.cell(row=3, column=8,value="Спортивное отделение").font=Font(size='11', bold=True)
sheet['H3'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True) 

sheet.cell(row=3,column=11).border=up_r_l
sheet.cell(row=3, column=11,value="Преподаватель").font=Font(size='11', bold=True)
sheet['K3'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True) 

sheet.cell(row=3,column=6).border=up_r_l 
tick=int(input("Введите номер студенческого билета: "))
name=input("Введите ФИО: ")
group=int(input("Группа: "))
num=input('Номер шахматного турнира: ')
wh1=input("В 1 партии белыми играл: ")
bk1=input("В 1 партии черными играл: ")
wh2=input("В 2 партии белыми играл: ")
bk2=input("В 2 партии черными играл: ")

sheet.cell(row=4, column=2,value=tick).font=Font(size='11', bold=True)
sheet['B4'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True) 

sheet.cell(row=4,column=3).border=up_r_l
sheet.cell(row=4, column=3,value=name).font=Font(size='11', bold=True)
sheet['C4'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True) 


sheet.cell(row=4,column=7).border=up_r_l
sheet.cell(row=4, column=7,value=group).font=Font(size='11', bold=True)
sheet['G4'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True) 

sheet.cell(row=4,column=8).border=up_r_l
sheet.cell(row=4, column=8,value="Шахматы").font=Font(size='11', bold=True)
sheet['H4'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True) 

sheet.cell(row=4,column=11).border=up_r_l
sheet.cell(row=4, column=11,value="С.В. Иванов.").font=Font(size='11', bold=True)
sheet['K4'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

bold_up_down=Border(top=Side(style='medium'),bottom=Side(style="medium"))
sheet.cell(row=4, column=4).border = bold_up_down;sheet.cell(row=4, column=5).border = bold_up_down;sheet.cell(row=4, column=9).border = bold_up_down;sheet.cell(row=4, column=12).border = bold_up_down;
rght=Border(right=Side(style='thin'))
sheet.cell(row=4, column=1).border = rght;
up_bot_r=Border(right=Side(style='thin'),bottom=Side(style='medium'),top=Side(style='medium'))
sheet.cell(row=4, column=6).border = up_bot_r;sheet.cell(row=4, column=10).border = up_bot_r;sheet.cell(row=4, column=13).border = up_bot_r;

sheet.merge_cells('B7:G7')
sheet.merge_cells('H7:M7')
sheet.merge_cells('B8:G8')
sheet.merge_cells('H8:M8')
sheet.merge_cells('C9:G9')
sheet.merge_cells('I9:M9')
sheet.merge_cells('C10:G10')
sheet.merge_cells('I10:M10')

sheet.cell(row=7, column=2,value="Шахматная партия №1").font=Font(size='11', bold=True)
sheet.cell(row=8, column=2,value=("Шахматный турнир №"+num+" "+date)).font=Font(size='11', bold=True)
sheet['B7'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True) 
sheet['B8'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

sheet.cell(row=7, column=8,value="Шахматная партия №2").font=Font(size='11', bold=True)
sheet.cell(row=8, column=8,value=("Шахматный турнир №"+num+" "+date)).font=Font(size='11', bold=True)
sheet['H7'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True) 
sheet['H8'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)
sheet.cell(row=9, column=2).border = thin_border; sheet.cell(row=10, column=2).border = thin_border; sheet.cell(row=9, column=8).border = thin_border; sheet.cell(row=10, column=8).border = thin_border
up_bot=Border(bottom=Side(style='thin'),top=Side(style='thin'))
for x in [3,4,5,6,7,9,10,11,12,13]:
    sheet.cell(row=9, column=x).border = up_bot;
    sheet.cell(row=10, column=x).border = up_bot;
sheet.cell(row=10, column=14).border = left; sheet.cell(row=9, column=14).border = left

sheet.cell(row=9, column=2,value="Белые").font=Font(size='11', bold=True)
sheet['B9'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)
sheet.cell(row=10, column=2,value="Черные").font=Font(size='11', bold=True)
sheet['B10'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)
sheet.cell(row=9, column=8,value="Белые").font=Font(size='11', bold=True)
sheet['H9'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)
sheet.cell(row=10, column=8,value="Черные").font=Font(size='11', bold=True)
sheet['H10'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

sheet.cell(row=9, column=3,value=wh1).font=Font(size='11')
sheet['C9'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)
sheet.cell(row=10, column=3,value=bk1).font=Font(size='11')
sheet['C10'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

sheet.cell(row=9, column=9,value=wh2).font=Font(size='11')
sheet['I9'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)
sheet.cell(row=10, column=9,value=bk2).font=Font(size='11')
sheet['I10'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

sheet.cell(row=42, column=6,value="Белые")
sheet.cell(row=42, column=7,value="Черные")
sheet.cell(row=43, column=5,value="Итог:")
if s[-3][-4]=='1' and s[-3][-3]!='/': #победа белых
    sheet.cell(row=43, column=6,value="побед").font=Font(size='11')
    sheet.cell(row=43, column=7,value="пораж").font=Font(size='11')
elif s[-3][-4]=='0' and s[-3][-3]!='/': #победа 4eph
    sheet.cell(row=43, column=7,value="побед").font=Font(size='11')
    sheet.cell(row=43, column=6,value="пораж").font=Font(size='11')
else: #pat
    sheet.cell(row=43, column=7,value="пат").font=Font(size='11')
    sheet.cell(row=43, column=6,value="пат").font=Font(size='11')

url=input('Введите ссылку на вторую игру: ')
if "white" in url:
    url=url[:url.index('white')-1]
if "black" in url:
    url=url[:url.index('black')-1]
link=url[url.index('/',10)+1::]
url='https://lichess.org/game/export/'+link+'?evals=0&clocks=0'

wget.download(url, link+'.txt')
s=list(map(str, open(link+'.txt')))

game=['/']*122
game_local=s[-3].split(' ')


game_local=[a for a in game_local if int(a[0],36)>=10]
for i in range(len(game_local)):
    game[i]=game_local[i]

for i in range(len(game_local)):
    game[i]=game_local[i]

flag=True;
for i in range(32):
    sheet.cell(row=14+i, column=9).value=game[i*2]
    sheet.cell(row=14+i, column=10).value=game[i*2+1]
    if i==31: break
else:
    flag=False;
if flag:
    for i in range(32, 61):
        sheet.cell(row=i-18, column=12).value=game[i*2]
        sheet.cell(row=i-18, column=13).value=game[i*2+1]
        
sheet.cell(row=42, column=12,value="Белые")
sheet.cell(row=42, column=13,value="Черные")
sheet.cell(row=43, column=11,value="Итог:")
if s[-3][-4]=='1' and s[-3][-3]!='/': #победа белых
    sheet.cell(row=43, column=12,value="побед").font=Font(size='11')
    sheet.cell(row=43, column=13,value="пораж").font=Font(size='11')
elif s[-3][-4]=='0' and s[-3][-3]!='/': #победа 4eph
    sheet.cell(row=43, column=13,value="побед").font=Font(size='11')
    sheet.cell(row=43, column=12,value="пораж").font=Font(size='11')
else: #pat
    sheet.cell(row=43, column=13,value="пат").font=Font(size='11')
    sheet.cell(row=43, column=12,value="пат").font=Font(size='11')

sheet.cell(row=13, column=2,value="№").font=Font(size='11')
sheet['B13'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

sheet.cell(row=13, column=3,value="Белые").font=Font(size='11')
sheet['C13'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

sheet.cell(row=13, column=4,value="Черные").font=Font(size='11')
sheet['D13'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

sheet.cell(row=13, column=5,value="№").font=Font(size='11')
sheet['E13'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

sheet.cell(row=13, column=6,value="Белые").font=Font(size='11')
sheet['F13'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

sheet.cell(row=13, column=7,value="Черные").font=Font(size='11')
sheet['G13'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

sheet.cell(row=13, column=8,value="№").font=Font(size='11')
sheet['H13'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

sheet.cell(row=13, column=9,value="Белые").font=Font(size='11')
sheet['I13'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

sheet.cell(row=13, column=10,value="Черные").font=Font(size='11')
sheet['J13'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

sheet.cell(row=13, column=11,value="№").font=Font(size='11')
sheet['K13'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

sheet.cell(row=13, column=12,value="Белые").font=Font(size='11')
sheet['L13'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

sheet.cell(row=13, column=13,value="Черные").font=Font(size='11')
sheet['M13'].alignment = Alignment(horizontal="center", vertical="center",wrap_text=True)

wb.save("Otchet_TK_FViS_"+str(tick)+'_'+date.replace('.','-')+'.xlsx')