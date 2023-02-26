from cs50 import get_float


# Taking input


def actual_dollars(actual_dollar):

    count_actualdollar = 0
    count_actualdollar = actual_dollar * 4
    return count_actualdollar


def quarters(cents):
    count_quarters = 0
    while(cents >= 25):
        cents = cents - 25
        count_quarters = count_quarters + 1
    return count_quarters


def dimes(cents):
    count_dimes = 0
    while(cents >= 10):
        cents = cents - 10
        count_dimes = count_dimes + 1
    return count_dimes


def nickles(cents):
    count_nickles = 0
    while(cents >= 5):
        cents = cents - 5
        count_nickles = count_nickles + 1
    return count_nickles


def pennies(cents):
    count_pennies = 0
    while(cents >= 1):
        cents = cents - 1
        count_pennies = count_pennies + 1
    return count_pennies


# main function for calling
def main():

    while True:
        dollars = get_float("Change owed: ")

        if dollars > 0:
            a = 5
            dollars = '%.2f' % dollars
            #print(f"dollars= {dollars}")
            #print("dollars =",dollars)
            # converting to strings
            list1 = (str(dollars)).split(".")
            # print(list1)
            actual_dollar = int(list1[0])

            cents = float(list1[1])
            # print("{0:.2f}".format(cents))
            break

    # calculate the number of  quarters give
    count_quarters = quarters(cents)
    cents = cents - count_quarters * 25

    # dimes
    count_dimes = dimes(cents)
    cents = cents - count_dimes * 10

    # nickles
    count_nickels = nickles(cents)
    cents = cents - count_nickels * 5

    # pennies

    count_pennies = pennies(cents)
    cents = cents - count_pennies * 1

    count_actualdollar = actual_dollars(actual_dollar)

    coins = count_actualdollar + count_quarters + count_dimes + count_nickels + count_pennies
    print(f"{coins}")


main()
