# Earthquake Predictor

## Table of Contents

- [Authors](#authors)
- [Introduction](#introduction)
- [Installations](#installations)
- [Import Libraries](#import-libraries)
- [Data](#data)
- [Data Preprocessing](#data-preprocessing)
- [Feature Selection](#feature-selection)
- [Hyperparameter Tuning using Grid Search](#hyperparameter-tuning-using-grid-search)
- [Artificial Neural Network](#artificial-neural-network)
- [Regression Metrics](#regression-metrics)
- [Model Optimization and Boosting](#model-optimization-and-boosting)
- [XGBoost](#xgboost)
- [Predictions](#predictions)
- [Visualizations](#visualizations)
- [Conclusion](#conclusion)

## Authors:  

Fatima Azfar
Komal Akhlaq

## Introduction:

This project develops an artificial intelligence model to predict the magnitude of earthquakes based on the location and time of occurrence. A machine learning approach utilizing neural networks is employed for modelling. The network architectures are designed, trained, and evaluated for accuracy using regression metrics. Visualizations of earthquake data provide further insights into the model's performance.

## Installations:

To run this code, you need to have Python 3 installed along with the following libraries:

- `Pandas`
- `Matplotlib`
- `Keras`
- `Sklearn`
- `Plotly`
- `XGBoost`

You can install these libraries using pip or any other package manager for python. For example, to install Pandas, you can use the following command in your terminal:

```
pip install pandas
```

Similarly, you can install other libraries by replacing pandas with the name of the library you want to install.

## Import Libraries
We import the following libraries:

- `numpy` and `pandas` for data manipulation
- `matplotlib.pyplot` for visualization 
- `datetime` for date/time manipulation
- `sklearn.preprocessing` for scaling and normalization
- `keras` for building the neural network
- `sklearn.model_selection` for train/test split and grid search
- `sklearn.metrics` for evaluating the model
- `plotly.express` for interactive visualizations
- `xgboost` for boosting

## Data:

The data represents a collection of earthquake events that occurred between `January 1965` and `December 2016`. Each row represents a single earthquake event and contains information such as the date and time of the event, the latitude and longitude of the earthquake's epicenter, the type of earthquake, its depth, magnitude, and other seismic parameters.

The columns in the data are:

- `Date`: The date of the earthquake event in mm/dd/yyyy format.
- `Time`: The time of the earthquake event in hh:mm:ss format.
- `Latitude`: The latitude of the earthquake's epicenter in decimal degrees.
- `Longitude`: The longitude of the earthquake's epicenter in decimal degrees.
- `Type`: The type of earthquake, such as "Earthquake" or "Nuclear Explosion".
- `Depth`: The depth of the earthquake's focus in kilometers.
- `Depth Error`: The estimated standard error of the reported depth.
- `Depth Seismic Stations`: The number of seismic stations used to calculate the reported depth.
- `Magnitude`: The magnitude of the earthquake on the Richter scale.
- `Magnitude Type`: The type of magnitude reported, such as ML, MS, or MW.
- `Magnitude Error`: The estimated standard error of the reported magnitude.
- `Magnitude Seismic Stations`: The number of seismic stations used to calculate the reported magnitude.
- `Azimuthal Gap`: The azimuthal gap in degrees, which measures the range of azimuths over which the seismic waves were measured.
- `Horizontal Distance`: The horizontal distance from the epicenter to the nearest station in degrees of arc.
- `Horizontal Error`: The estimated standard error of the reported horizontal distance.
- `Root Mean Square`: The root mean square error of the waveform fitting.
- `ID`: The identification code of the earthquake event.
- `Source`: The source of the earthquake data.
- `Location Source`: The source of the location data.
- `Magnitude Source`: The source of the magnitude data.
- `Status`: The status of the event (automatic or reviewed)

## Data Preprocessing
We select the relevant columns from the data:

- `Date` 
- `Time`
- `Latitude`
- `Longitude`
- `Depth`
- `Magnitude`

We then convert the `Date` and `Time` columns to Unix timestamps using the `datetime` library. Any rows with errors in the date/time format are assigned a `"ValueError"` for the timestamp. 

We drop the `Date` and `Time` columns and any rows with `"ValueError"` for the timestamp. The data is ready for modeling!

## Feature Selection

We train a random forest model with 100 trees using the RandomForestRegressor class from scikit-learn to obtain `feature importances`. We then get the feature importances and sort them in descending order. We then select the top k features and print their names. We selected the top 3 features based on their importance scores, but you can change the value of k to select a different number of features.

Feature selection using Random Forest is a popular method as it provides a ranking of the most important features for the task at hand. The selected features can then be used to train a model with improved performance and reduced complexity.

## Hyperparameter Tuning using Grid Search
We split the data into 80% train and 20% test using `train_test_split`. We scale the train and test sets separately using the `StandardScaler` from `sklearn.preprocessing`.

We define a Keras model builder function `create_model()` with hyperparameters:

- `num_layers` - Number of layers 
- `num_neurons` - Number of neurons per layer
- `activation` - Activation function
- `optimizer` - Optimizer 

We perform grid search on these hyperparameters using `GridSearchCV` to find the best model.

## Artificial Neural Network
We build the model with the best hyperparameters from the grid search. We compile the model  with `mse` loss, `adam` optimizer, and `mae` metric. 

We fit the model for 50 epochs with a batch size of 32. 

We evaluate the model on the test set and print the MSE and MAE.

## Regression Metrics
We calculate various regression metrics to evaluate the model:

- `Accuracy` 
- `Precision`
- `Recall`
- `F1 Score`
- `Mean Absolute Error (MAE)`
- `Root Mean Squared Error (RMSE)`
- `Mean Absolute Percentage Error (MAPE)`

We also print the confusion matrix.

## Model Optimization and Boosting
We optimize the model by:

- Adding dropout regularization after each hidden layer to prevent overfitting
- Using early stopping which monitors the validation loss and stops training if there is no improvement for 10 epochs. 
- We fit the model with a validation split of 0.2 and the early stopping callback.

We again evaluate the optimized model on the test set and calculate the regression metrics.

## XGBoost
We generate predictions on the training and testing data using the optimized Keras model. We convert these predictions to a binary classification format that XGBoost can handle using `xgb.DMatrix()`.

We train an XGBoost model for 100 rounds and make predictions on the training and testing data. We convert these predictions back to binary labels and calculate the accuracy.

## Predictions
We create example input data and scale it using the `StandardScaler` from before. 

We generate predictions on this example data using our optimized Keras model and format the predictions into a DataFrame with the original input data.

## Visualizations
We create various visualizations using Plotly Express:

- Mapbox scatter plot of earthquake locations
![Earthquake Locations](plot1.png)
- Line chart of magnitudes over time
![Earthquake Overtime](newplot2.png)
- Histogram of magnitude distribution
![Magnitude Distribution](newplot3.png)
- Scatter plot of magnitude vs depth 
![Magnitude vs Depth](newplot4.png) 
- Mapbox plot of earthquake counts by location
![Earthquake Counts by Location](newplot5.png)
- Density map of affected areas
![Affected Areas](newplot6.png)

The visualizations provide insights into the data and model predictions.

## Conclusion:

The model provides a reasonable initial capability to predict earthquake magnitudes and depths based on location and time. The visualizations highlight its performance in different regions and limitations that could be addressed through enhancements:

- Incorporating more features like soil type, tectonic plate movement, etc
- Using advanced deep learning models and training on larger datasets
- Performing error analysis to identify and improve model deficiencies