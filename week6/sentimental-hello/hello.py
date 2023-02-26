import csv

with open(filename, "r") as file:
    reader = csv.Dictreader(file)
    print(row["title"])