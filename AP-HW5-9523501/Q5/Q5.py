#Question5
import os

#Create directory
def create_dir(name,address):
        if not os.path.exists(address + "\\" + name):
            os.makedirs(address + "\\" + name)
        else:
            print('Error: Creating directory. ' + address + "\\" + name)

#Create file
def create_file(name,address):
        if not os.path.isfile(address + "\\" + name):
            open(address + "\\" + name,'a')
        else:
            print('Error: Creating File. ' + address + "\\" + name)
#Delete file
def delete(name,address):
    if os.path.isfile(address + "\\" + name):
        os.remove(address + "\\" + name)
    else:
        print('Error: Removing File. ' + address + "\\" + name)

#Find file
def find(name,address):
    A=[]
    for file in os.listdir(address):
        if os.path.isfile(os.path.join(address, name)):
            A = os.getcwd()
    print(A)

print('please enter your filename:')
fileName = input()
print('please enter your directory:')
fileDir = input()
create_dir(fileName,fileDir)
create_file(fileName + '.txt',fileDir)
print('find created file at:')
find(fileName + '.txt',fileDir)
delete(fileName + '.txt',fileDir)
print('find created file after delete function called')
find(fileName + '.txt',fileDir)