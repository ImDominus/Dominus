w, b = 0, 0
z = np.dot(w.t, x) + b  #z = w.t*x + b
A = sigmoid(z)
dz = A - y
dw = 1/m * X * dz.t
db = 1/m * np.sum(dz)
w = w - alpha * dw
b = b - alpha * db
