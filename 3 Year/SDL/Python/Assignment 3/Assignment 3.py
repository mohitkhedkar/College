import pandas as pd 
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv('medals_data.csv')

df[['Gold','Silver','Bronze']].plot(kind='bar',stacked=True)
plt.title('India Olympics Medal')
plt.xlabel('Years')
plt.ylabel('Medals')
n = len(df['Games'])
labels = df.Games.str.slice(0,4)
plt.xticks(np.arange(n),labels,rotation='horizontal')
plt.show()