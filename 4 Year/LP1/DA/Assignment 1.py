# Assignment - 1: Download the Iris flower dataset or any other dataset into a Data Frame. (eg https://archive.ics.uci.edu/ml/datasets/Iris ) Use Python/R and Perform following – 
# • How many features are there and what are their types (e.g., numeric, nominal)? 
# • Compute and display summary statistics for each feature available in the dataset. (eg. minimum value, maximum value, mean, range, standard deviation, variance and percentiles 
# • Data Visualization-Create a histogram for each feature in the dataset to illustrate the feature distributions. Plot each histogram. 
# • Create a boxplot for each feature in the dataset. All of the boxplots should be combined into a single plot. Compare distributions and identify outliers 


# Load libraries
import pandas
import matplotlib.pyplot as plt

# Load dataset
url = "https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data"
names = ['sepal-length', 'sepal-width', 'petal-length', 'petal-width', 'class']
dataset = pandas.read_csv(url, names=names)

# shape
print(dataset.shape)

# head
print(dataset.head(20))

# descriptions
print(dataset.describe())

# class distribution
print(dataset.groupby('class').size())


# histograms
dataset.hist()
plt.show()

# box and whisker plots
dataset.plot(kind='box', subplots=True, layout=(2,2), sharex=False, sharey=False)
plt.show()

