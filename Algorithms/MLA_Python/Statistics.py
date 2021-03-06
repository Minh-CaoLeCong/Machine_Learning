from collections import Counter
from LinearAlgebra import *
import math

def mean(x):
    return sum(x) / len(x)

def median(x):
    """
    Finds the 'middle-most' value of x which is the middle-most value
    if the number of data points is odd or the average of the two middle-most values
    if the number of data points is even.
    """
    xLen = len(x)
    xSorted = sorted(x)         # sorting
    midpoint = xLen // 2

    if xLen % 2 == 1:
        # return the middle-most value if odd
        return xSorted[midpoint]
    else:
        # return the average of the middle values if even
        return (xSorted[midpoint - 1] + xSorted[midpoint]) / 2

def quantile(x, p):
    """
    Returns the pth-percentile value in x.
    """
    p_index = int(p * len(x))
    xSorted = sorted(x)
    return xSorted[p_index]

def mode(x):
    """
    Returns a most-common value (list), might be more than one mode.
    """
    counts = Counter(x)
    maxCounts = max(counts.value())
    return [x_i for x_i, count in counts.iteritems()
            if count == maxCounts]

def dataRange(x):
    """
    0 if the max and min are equal or the elements of x are all the same.
    """
    return max(x) - min(x)

def deMean(x):
    """
    Translate x by subtracting its mean (so the result has mean 0).
    """
    xBar = mean(x)
    return [x_i - xBar for x_i in x]

def variance(x):
    """
    Assumes x has at leats two elements.
    """
    xLen = len(x)
    deviations = deMean(x)
    return sumSquares(deviations) / (xLen - 1) # 'sumSquares' in LinearAlgebra.py

def standardDeviation(x):
    return math.sqrt(variance(x))

def interquartileRange(x):
    return quantile(x, 0.75) - quantile(x, 0.25)

def covariance(x, y):
    xLen = len(x)
    return dotProduct(deMean(x), deMean(y)) / (n - 1)

def correlation(x, y):
    standardDeviation_x = standardDeviation(x)
    standardDeviation_y = standardDeviation(y)
    if standardDeviation_x > 0 and standardDeviation_y > 0:
        return covariance(x, y) / standardDeviation_x / standardDeviation_y
    else:
        return 0