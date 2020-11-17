# Write python code that loads any dataset (example Game_medal.csv), and does some basic data cleaning. Add component ondata set.

# Author: Mohit Khedkar.

import matplotlib.pyplot as plt
import numpy as np
import csv

# write Data into CSV file

# Scatter Plot
Unemployment_Rate = [6.1,5.8,5.7,5.7,5.8,5.6,5.5,5.3,5.2,5.2]
Stock_Index_Price = [1500,1520,1525,1523,1515,1540,1545,1560,1555,1565]

data = list(zip(Unemployment_Rate, Stock_Index_Price)) 

with open("ScatterPlot.csv",'w') as f:
    writer = csv.writer(f,lineterminator="\n")
    writer.writerow(("Unemployment_Rate","Stock_Index_Price"))
    writer.writerows(data)


# For Line Plot

Year = [1920,1930,1940,1950,1960,1970,1980,1990,2000,2010]
Unemployment_Rate = [9.8,12,8,7.2,6.9,7,6.5,6.2,5.5,6.3]

data = list(zip(Year, Unemployment_Rate)) 

with open("LinePlot.csv",'w') as f:
    writer = csv.writer(f,lineterminator="\n")
    writer.writerow(("Year", "Unemployment_Rate"))
    writer.writerows(data)


# for Bar Chart

Country = ['USA','Canada','Germany','UK','France']
GDP_Per_Capita = [45000,42000,52000,49000,47000]

data = list(zip(Country, GDP_Per_Capita)) 

with open("BarPlot.csv",'w') as f:
    writer = csv.writer(f,lineterminator="\n")
    writer.writerow(("Country", "GDP_Per_Capita"))
    writer.writerows(data)



# Plotting Graphs

# Scatter Plot

with open("ScatterPlot.csv",'r') as f:
    reader = csv.reader(f)
    Unemployment_Rate , Stock_Index_Price  = map(list, zip(*reader))

Unemployment_Rate.pop(0)
Stock_Index_Price.pop(0)

plt.scatter(Unemployment_Rate, Stock_Index_Price, color='green')
plt.title('Unemployment Rate Vs Stock Index Price', fontsize=14, fontweight="bold")
plt.xlabel('Unemployment Rate', fontsize=14)
plt.ylabel('Stock Index Price', fontsize=14)
plt.grid(True)
plt.show()


# Line Chart

with open("LinePlot.csv",'r') as f:
    reader = csv.reader(f)
    Year, Unemployment_Rate = map(list, zip(*reader))

Year.pop(0)
Unemployment_Rate.pop(0)

plt.plot(Unemployment_Rate, Stock_Index_Price, color='green')
plt.title('Unemployment Rate Vs Year', fontsize=14, fontweight="bold")
plt.xlabel('Year', fontsize=14)
plt.ylabel('Unemployment Rate', fontsize=14)
plt.grid(True)
plt.show()


# Bar Chart

with open("BarPlot.csv",'r') as f:
    reader = csv.reader(f)
    Country, GDP_Per_Capita = map(list, zip(*reader))

Country.pop(0)
GDP_Per_Capita.pop(0)

xAxis = [i + 0.5 for i, _ in enumerate(Country)]
plt.bar(xAxis, GDP_Per_Capita, color='teal')
plt.title('Country Vs GDP Per Capita', fontsize=14)
plt.xlabel('Country', fontsize=14)
plt.ylabel('GDP Per Capita', fontsize=14)
plt.xticks([i + 0.5 for i, _ in enumerate(Country)], Country)
plt.show()