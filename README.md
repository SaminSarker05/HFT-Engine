- use an API to get real time data on stock price, volume, bid/ask, etc
- place buy and sell orders and track 
- minimize latency
- algo to generate buy/sell signal
- risk management (hedging)

- pairs trading
- mean reversion
- momentum trading
- cointegration

Today:
- build API to gather stock data; TESLA
- trying Polygon.io

API KEY = zZyYBE2053mhvMXe7oT9nxftLZKtOJ9w
make a get request to api endpoint to get aggregate data of stock within a date range
https://api.polygon.io/v2/aggs/ticker/AAPL/range/1/day/2023-01-09/2023-02-10?adjusted=true&sort=asc&apiKey=zZyYBE2053mhvMXe7oT9nxftLZKtOJ9w