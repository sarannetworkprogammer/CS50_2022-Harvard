'''
import csv
import sys


def main():

    dict1 = {}

    # TODO: Check for command-line usage

    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")
# first part done
# TODO: Read database file into a variabl
# TODO: Read DNA sequence file into a variable

    filename = sys.argv[2]

    f = open(filename)
    sequence = f.read()
# done here

#################################

    with open(sys.argv[1]) as file_obj:

        # Create reader object by passing the file
        # object to reader method
        reader_obj = csv.reader(file_obj)
        row1 = next(reader_obj)
        required = row1[1:]
        # print(f"required:{required}")
        # print(len(required))

        for ele in required:
            #print(f"ele :{ele}")
            longest_run = longest_match(sequence, ele)
            dict1[ele] = longest_run

            # print(ele,longest_run)

        keys_values = dict1.items()
        new_dict1 = {str(key): str(value) for key, value in keys_values}
        #print(f"new_dict1: {str(new_dict1)}")

    # Iterate over each row in the csv
    # file using reader object

    # TODO: Find longest match of each STR in DNA sequence

    #subsequence = "AGATC"

    #longest_run = longest_match(sequence, subsequence)
    #print(f"longest_run {longest_run}")

    # TODO: Check database for matching profiles

    with open(sys.argv[1], mode='r') as file:
        csvFile = csv.DictReader(file)
        a = 0
        for lines in csvFile:
            # print("lines = ",lines[1:])
            d1 = dict(list(lines.items())[1:])
            # print(f"d1:{d1}")
            if new_dict1 == d1:
                a = a + 1
                # print("found")
                d2 = dict(list(lines.items())[:1])
                d2.items()
                l1 = list(d2.items())
                print(l1[0][1])
        if (a != 1):
            print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
'''


import csv



filename = "databases/large.csv"

with open(filename ,"r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row["name"])