import argparse

# load data from file
def loadfile(filename):
    f = open(filename,"r")
    rawdata = f.read()
    lines = rawdata.split("\n")
    data = []
    for i in range(len(lines)-2):
        lines[i+1] = lines[i+1].split("\t")
        data.append(lines[i+1])
    return data

# create a dictionary for assigning ids to names
def namehash(indata):
    mydict = {}
    # iterate through data using format:
    # key = actor name
    # 3 data points are actor id,birth year,death year respectively
    for x in indata:
        mydict.update({x[1]:[x[0],x[2],x[3]]})
    return mydict

# create a dictionary for assigning movies to their ids
def moviehash(indata):
    mydict = {}
    # iterate through data using format:
    # key = movie name
    # 2 data points are movie id,year producted
    for x in indata:
        mydict.update({x[2]:[x[0],x[5]]})
    return mydict

# create a dictionary for assigning movie ids to stars
def starhash(indata):
    mydict = {}
    # iterate through data using format
    # key = actor id
    # 2 data points are movie id,role played by actor
    for x in indata:
        # if actor id not in dict update it with data points
        if x[2] not in mydict:
            mydict.update({x[2]:[[x[0]],[x[5]]]})
        # if actor in dict update each data point by adding the new movie id and starring role to list
        else:
            mydict[x[2]][0].append(x[0])
            mydict[x[2]][1].append(x[5])
    return mydict

# create a dictionary for assigning movie ids to movies
def movieidhash(indata):
    mydict = {}
    # iterate through movie using format:
    # key = movie id
    # 2 data points are movie name,year produced
    for x in indata:
        mydict.update({x[0]:[x[2],x[5]]})
    return mydict

# part 1 
def searchmovie(indict,title):
    # search dictionary made by title and if title found print name and production year
    if title in indict:
        print("The movie",title,"was made in",indict[title][1])
    else:
        print("Not Found")

# part 2
def searchactor(indict,name):
    # search dictionary made by name and if name found print name and brith year and if they are dead print death year
    if name in indict:
        if indict[name][2] == str(r"\N"):
            print(name,"was born in",indict[name][1])
        else:
            print(name,"was born in",indict[name][1],"and died in",indict[name][2])
    else:
        print("Not Found")

# part 3
def starredinby(starsdict,namedict,moviedict,name):
    # search dictionary and if they are then print their name and all the movies they've played in formatted nicely
    if name in namedict:
        work = starsdict[namedict[name][0]]
        print("\n"+name,"starred in the following movies:\n")
        for i in range(len(work[0])):
            print(moviedict[work[0][i]][0], "in",moviedict[work[0][i]][1] , "as", str(work[1][i]).replace("[","").replace("]","").replace('"',""))

def part1(input):
    ### Part 1
    # load data 
    movies = loadfile("movies.tsv")
    # create dictionary with data
    moviedict = moviehash(movies)
    # search for the movie
    searchmovie(moviedict,input[0])

def part2(input):
    ### Part 2
    # load data
    names = loadfile("names.tsv")
    # create dictionary with data
    namedict = namehash(names)
    # search for the actor
    searchactor(namedict,input[0])

def part3(input):
    ### Part3
    # load data and create dictinoaries
    names = loadfile("names.tsv")
    namedict = namehash(names)
    movies = loadfile("movies.tsv")
    moviedict = movieidhash(movies)
    stars = loadfile("starring_roles.tsv")
    starsdict = starhash(stars)
    # search for the actor and all the movies they starred in
    starredinby(starsdict,namedict,moviedict,input[0])

# Parse arguments
def getopts():
    
    # Arg for slecting which type of lookup
    parser = argparse.ArgumentParser()
    parser.add_argument('option',type=int, nargs='?', 
                        default=0, help="Search Option : Movie Lookup (part1),Actor Lookup (part2), Movies Starred In By Actor (part3),1,2,3")
    
    # Arg for what you are looking up
    parser.add_argument('lookup',type =str, nargs='*',default = None, help="Enter In Actor Or Movie Name With Quotations Around It Example 'Steve Buscemi'")

    # parse command line
    opts = parser.parse_args()
    option = opts.option
    lookup = opts.lookup

    if option not in [1,2,3]:
        raise ValueError("Specify Lookup Option 1,2, or 3")
    return [option,lookup]

def main():
    # get 
    opt = getopts()
    
    if opt[0] == 1:
        part1(opt[1])
    elif opt[0] == 2:
        part2(opt[1])
    elif opt[0] == 3:
        part3(opt[1])

main()