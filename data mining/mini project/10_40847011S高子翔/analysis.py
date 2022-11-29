import numpy as np
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier

train = pd.read_csv("train.csv")
test = pd.read_csv("test.csv")

# preprocessing
NaN_col_names = ["glucose_concentration", "blood_pressure", "skin_fold_thickness", "serum_insulin", "bmi", "diabetes pedigree"]
train[NaN_col_names] = train[NaN_col_names].replace(0, np.NaN)
test[NaN_col_names] = test[NaN_col_names].replace(0, np.NaN)

# 得到各項中間值後填入 missing data
train_medians = train.median()
train = train.fillna(train_medians)

test_medians = train.median()
test = test.fillna(test_medians)

y_train = train["diabetes"]
x_train = train.drop(["diabetes", "p_id"], axis = 1)
only_id = pd.DataFrame(test["p_id"])
test = test.drop(["p_id"], axis = 1)
# 數據標準化
Scaler = StandardScaler()
x_train = Scaler.fit_transform(x_train)
test = Scaler.fit_transform(test)

# 訓練模型
neigh = KNeighborsClassifier(n_neighbors = 3)
neigh.fit(x_train, y_train)

# 得到測試結果
predict_result = neigh.predict(test)

only_id["diabetes"] = predict_result
result = only_id

result.to_csv("result.csv", index = False)
