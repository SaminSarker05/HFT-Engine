- use an API to get real time data on stock price, volume, bid/ask, etc
- place buy and sell orders and track 
- minimize latency
- algo to generate buy/sell signal
- risk management (hedging)
- python, sockets, NLP

- pairs trading
- mean reversion
- momentum trading
- cointegration

two APIs,
- one gathers information about a stock every 5 minutes
- other makes move paper traded moves on market 

1. ingest real time financial data, from various exchanges and data providers
  - reduce latency

2. signal generation

3. order execution

https://github.com/nlohmann/json

voting system? have 5 algos race and generate buy, hold, sell signal. 
we take majority of first 4 returned and excecute trade

use alpaca API to make paper trades on live market
- will start with 100k and simulate our profits/loss using algos
