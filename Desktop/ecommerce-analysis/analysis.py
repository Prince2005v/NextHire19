import pandas as pd
import matplotlib.pyplot as plt

# Load dataset
df = pd.read_csv("data.csv", encoding='latin1')

# Show first rows
print(df.head())

# Remove missing values
df = df.dropna()

# Create total price column
df["TotalPrice"] = df["Quantity"] * df["UnitPrice"]

# Top selling products
top_products = (
    df.groupby("Description")["TotalPrice"]
    .sum()
    .sort_values(ascending=False)
    .head(10)
)

print(top_products)

# Plot graph
top_products.plot(kind="bar")

plt.title("Top Selling Products")
plt.xlabel("Products")
plt.ylabel("Sales")

plt.tight_layout()
plt.show()