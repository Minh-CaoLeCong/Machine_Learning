'''
The K Nearest Neighbors Algorithm (KNN)
1.  Load the training dataset
2.  Initialize K to your chosen number of neighbors
3.  For each training data in the training dataset
    3.1 Calculate the distance between the testing data point and
        the current training data point
    3.2 Add the distance and the index of the training data to
        an ordered collection
4.  Sort the ordered collection of distances and indices
    from smallest to largest (in ascending order) by the distances
5.  Pick the first K entries from the sorted collection
6.  Get the labels of the selected K entries
7.  If regression, return the mean of the K labels
8.  If classification, return the mode of the K labels
'''

# import the necessary packages
from collections import Counter
import math

def KNearestNeighbors1(training_dataset, testing_dataset, k, 
                    calculation_distance_method, choice_method):

    # Create a list to store distance between testing point and
    # each training data
    neighbor_distances_and_indices = []

    # 3. For each training data in the training dataset
    for index, training_data in enumerate(training_dataset):

        # 3.1 Calculate the distance between the testing data point
        # and the current training data point
        distance = calculation_distance_method(training_data[:-1],
                                                    testing_dataset)
                
        # 3.2 Add the distance and the index of the training data to
        # an ordered collection
        neighbor_distances_and_indices.append((distance, index))

    # 4. Sort the ordered collection of distances and indices from 
    #    smallest to largest (in ascending order) by the distances
    sorted_neighbor_distances_and_indices = sorted(neighbor_distances_and_indices)

    # 5. Pick the first K entries from the sorted collection
    kNN_distance_and_indices = sorted_neighbor_distances_and_indices[:k]

    # 6. Get the labels of the selected K entries
    kNN_labels = [training_dataset[i][1] for distance, i in kNN_distance_and_indices]

    # 7. If regression (choice_method = mean), return the average of the K labels
    # 8. If classification (choice_method = mode), return the mode of the K labels
    return kNN_distance_and_indices, choice_method(kNN_labels)

def euclidean_distance(point1, point2):
    '''
    Given are two point A and B (n dimension):
    A(a1, a2, ..., an)   B(b1, b2, ..., bn)
    => The Euclidean distance A to B is given by the Pythagorean formula:
    d(A, B) = d(B, A) = sqrt((a1 - b1)^2 + (a2 - b2)^2 + ... + (an - bn)^2)
    '''
    sum_squared_distance = 0
    for i in range(len(point1)):
        sum_squared_distance += math.pow(point1[i] - point2[i], 2)
    return math.sqrt(sum_squared_distance)

# kNN regression method
def mean(labels):
    return sum(labels) / len(labels)

# kNN classification method
def mode(labels):
    return Counter(labels).most_common(1)[0][0]

def KNearestNeighbors2(training_dataset_dict, testing_dataset_dic, k,
                        calculation_distance_method, choice_method):
    ''' 
    This function finds the classification of testing point using 
    k nearest neighbor algorithm. It assumes only two 
    groups and returns 0 if testing point belongs to group 0, else 
    1 (belongs to group 1). 
  
    training_dataset_dict:  Dictionary of training points having two keys
                            - 0 and 1. Each key have a list of 
                            training data points belong to that  
  
    testing_dataset_dic:    A tuple, test data point of the form (x,y) 
  
    k:                      number of nearest neighbour to consider,  
    '''

    neighbor_distances_and_group=[]
    for group in training_dataset_dict:
        for feature in training_dataset_dict[group]:
            # calculate the euclidean distance of testing point 
            # from training dataset 
            distance = calculation_distance_method(feature, testing_dataset_dic)

            neighbor_distances_and_group.append((distance, group))

    # sort the neighbor_distances_and_group list in ascending order 
    # and select first k distances
    neighbor_distances_and_group = sorted(neighbor_distances_and_group)[:k]
    # print(neighbor_distances_and_group)

    pre_labels = [neighbor_distances_and_group[i][1] for distance, i in neighbor_distances_and_group]
    # print(pre_labels)
    
    return choice_method(pre_labels)

def main():
    '''
    Classification Data:
        Column 0: age
        Column 1: likes reading story
    '''
    clf_training_data_list = [
       [10, 1],
       [13, 1],
       [15, 1],
       [20, 1],
       [23, 1],
       [26, 0],
       [27, 0],
       [29, 0],
       [31, 0],
       [45, 0],
    ]
    # Given the data we have, does a 30 year old like reading story?
    clf_testing_data_list = [30]

    clf_k_nearest_neighbors, clf_prediction = KNearestNeighbors1(
        clf_training_data_list, clf_testing_data_list, k=3, 
        calculation_distance_method=euclidean_distance, 
        choice_method=mode)

    # print(clf_k_nearest_neighbors)
    # print(clf_prediction)

    '''
    Dictionary of training points having two keys - 0 and 1:
        Class 0 corresponding to key 0
        Class 1 corresponding to key 1
    '''
    training_data_list_dic = {0:[(1,12),(2,5),(3,6),(3,10),(3.5,8),(2,11),(2,9),(1,7)], 
                                  1:[(5,3),(3,2),(1.5,9),(7,2),(6,1),(3.8,1),(5.6,4),(4,2),(2,5)]} 
    
    # testing point (x, y)
    testing_point = (2.5, 7)

    # number of neighbours
    k = 3

    print("The value classified to unknown point is: {}".format
                (KNearestNeighbors2(training_data_list_dic,testing_point,
                    k, calculation_distance_method=euclidean_distance, 
                    choice_method=mode)))



if __name__ == '__main__':
    main()