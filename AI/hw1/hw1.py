from numpy import *
import matplotlib.pyplot as plt
train_in = array([[0,2,0],[0,0,1],[0,1,1],[1,0,1],[1,1,1]])
train_sol = array([[0,0,0,1,1]]).T

# Initialize nn_weights
random.seed(1)
nn_weights = 2 * random.random((3, 1)) - 1

# Initialize the error array to draw the figure
error_points = []

# learning rate and epoch initialize
learning_rate = 1.5
epoch = 200

# Unknown test input
test_in = array([1,0,0])

# Train the network
for i in range(epoch):
    print("\n i= ", i, "nn_weight=")
    print(nn_weights)
    
    # Calculate the outputs for each training examples
    train_out = 1 / (1 + exp(-(dot(train_in, nn_weights))))
    print("train_out =")
    print(train_out)
    
    # calculate error
    error = 1.0 - (1/(1 + exp(-(dot(test_in, nn_weights)))))
    error_points.append(error)
    
    # Run the NN adjustments
    nn_weights += learning_rate * dot(train_in.T, (train_sol-train_out)*train_out*(1-train_out))

# draw figure
plt.plot(error_points)
plt.ylim(0.0, 0.6)
plt.title("learning rate = " + str(learning_rate) + ", epoch = " + str(epoch))
plt.xlabel("generation")
plt.ylabel("total error")
plt.show()	

# Print the result for our unknown test input
print('\nThe final prediction is ',1/(1 + exp(-(dot(test_in, nn_weights)))))