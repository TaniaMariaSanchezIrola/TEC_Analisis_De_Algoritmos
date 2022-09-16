import csv
import matplotlib.pyplot as plt
import numpy as np

linesList = []  #Points inside a Line
pointList =[]   #pairs list
squareOne = []  #single square with lines
squares = []    #N Squares

with open('testing 1.csv') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    for squareData in csv_reader:
        for square in squareData:
            square = square[:-1]
            squareOne = []
            lines = square.split("|")
            for line in lines:
                line = line
                pointList = line.split(";")
                linesList = []
                for indexPoint in range(0,len(pointList)-1,2):
                    linesList.append((int(pointList[indexPoint]), int(pointList[indexPoint+1])))
                squareOne.append(linesList)
                linesList = []
            squares.append(squareOne)
squares = squares[:-1]
            
print("Matplotlib graphication: ")

ax = plt.subplots()

print("Square")
print(square)
indexSquare =1
indexLines =1
for square in squares:
    indexLines = 1
    print("Square ", indexSquare)
    indexSquare +=1
    for line in square:
        print("Line ", indexLines)
        indexLines += 1
        print(line)
        listX = []      #lists to graph the X axis points inside a line
        listY = []      #lists to graph the Y axis points inside a line
        for point in line:
            listY.append(point[1])
            listX.append(point[0])
        plt.plot(listX, listY)
ax = plt.axis([0,400,0,400])
plt.show()