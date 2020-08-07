import math

def add2Vector(vec1, vec2):
    """
    Adds coressponding the elements of 2 vectors
    Example:    vec1 = [1,2,3]
                vec2 = [4,5,6]
                vec3 = add2Vector(vec1, vec2) # [5, 7, 9]
                vec4 = vec1 + vec2 # [1, 2, 3, 4, 5, 6]
    """
    return [vec1_i + vec2_i 
            for vec1_i, vec2_i in zip(vec1, vec2)]

def addVector(*vectors):
    """
    Sdds coressponding the elements of multiple vectors
    Example:    vec1 = [1,2,3]
                vec2 = [4,5,6]
                vec3 = [7,8,9]
                vec4 = addVector(vec1, vec2, vec3) # [12, 15, 18]
    """
    vec1 = vectors[0]
    for vec2 in vectors[1:]:
        vec1 = add2Vector(vec1, vec2)
    return vec1

def sub2Vector(vec1, vec2):
    """
    Subtacts coressponding the elements of 2 vectors
    Example:    vec1 = [1,2,3]
                vec2 = [4,5,6]
                vec3 = sub2Vector(vec2, vec1) # [3, 3, 3]
                vec4 = vec1 - vec2 # error
    """
    return [vec1_i - vec2_i 
            for vec1_i, vec2_i in zip(vec1, vec2)]

def sumVector(vectors):
    """
    Sums all corresponding elements
    Another way:
        def sumVector(vectors):
            return reduce(add2Vector, vectors)

        sumVector = partial(reduce, add2Vector)
    """
    result = vectors[0]                         # start with the first vector
    for vector in vectors[1:]:                  # then loop over the others
        result = add2Vector(result, vector)     # and add them to the result
    return result

def scalarMultiply(vector, number):
    """
    Multiply a vector by a scalar.
    Multiplying each element of the vector by that number.
    """
    return [number * vector_i for vector_i in vector]

def meanVector(vectors):
    """
    Compute the vector whose ith element is 
    the mean of the ith elements of the input vectors.
    """
    n = len(vectors)
    return scalarMultiply(1/n, sumVector(vectors))

def dotProduct(vec1, vec2):
    """
    The dot product of two vectors is the sum of their componentwise products.
    The dot product measures how far the vector 'vec1' extends in the 'vec2' direction.
    """
    return sum(vec1_i * vec2_i
                for vec1_i, vec2_i in zip(vec1, vec2))

def sumSquares(vec1):
    """
    vec1_1 * vec1_1 + ... + vec1_n * vec1_n
    """
    return dotProduct(vec1, vec1)

def magnitude(vec1):
    return math.sqrt(sumSquares(vec1)) # math.sqrt is square root function

def squaredDistance(vec1, vec2):
    """
    (vec1_1 - vec2_1) ** 2 + ... + (vec1_n - vec2_n) ** 2
    """
    return sumSquares(sub2Vector(vec1, vec2))

def distance(vec1, vec2):
    return math.sqrt(squaredDistance(vec1, vec2))
# another way
def distance1(vec1, vec2):
    return magnitude(sub2Vector(vec1, vec2))