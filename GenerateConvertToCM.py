import pandas as pd

print("Input File Name (Including format; e.g: ExcelSheet.xlsx):")
fileName = input()
df = pd.read_excel(fileName)
df = df.dropna(axis=0, how='any').reset_index()
print("\nGenerated Function:\n\n")
print("double convertToCM(double val){\n\tint dist;")
for i,rows in df.iterrows():
    if(i==0):
        prevcm=int(rows['cm'])
        prevval=int(rows['value'])
        print("\tif(val>"+str(prevval)+") dist="+str(prevcm)+";")

    else:
        dx=rows['cm']-prevcm
        dy=rows['value']-prevval
        m = dy/dx
        c = rows['value']-m*rows['cm']
        print("\telse if(val<="+str(prevval)+"&&val>"+str(int(rows['value']))+") dist=(val-"+str(c)+")/"+str(m)+"; //"+str(prevcm)+"cm to "+str(rows['cm'])+"cm")
        prevval = int(rows['value'])
        prevcm = rows['cm']
        if(i==len(df)-1):
            print("\telse dist="+str(rows['cm'])+";")
print("\treturn dist;\n}")