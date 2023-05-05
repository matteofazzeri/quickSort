import matplotlib.pyplot as plot

plot.style.use('ggplot')

# Obtain values for the histogram from text file.
nComp = []
file = open('results.txt','r')
file.seek(0)
for line in file.readlines():
    nComp.append(int(line))
file.close()

plot.title = 'Histogram APA'
bins = 50

plot.hist(nComp, bins, color="white", edgecolor="black")
plot.gca().set(title='|S|=10^4 , Run=10^5', xlabel='Confronti', ylabel='Run')



plot.savefig('Plot.png')
plot.close()
