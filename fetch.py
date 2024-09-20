"""
sumarry
"""
import threading
import yfinance as yf
import time
import json
import os

# download stock data using yfinance API
def make_api_call(ticker):
  data = yf.download(tickers=ticker, interval="1m", period="1d")
  return data

# save in JSON format
def save_to_json(data, filename):
  data_dict = data.to_dict(orient='records')
  with open(filename, 'w') as f:
    json.dump(data_dict, f, indent=3)

# fetch data every minue
def fetch_data(ticker):
  while True:
    data = make_api_call(ticker)
    save_to_json(data, f'{ticker}.json')
    print(f'wrote to file for {ticker}')
    time.sleep(60)

def main():
  tickers = ['AAPL', 'MSFT']
  threads = []
  # create threads to concurrently grab data
  for ticker in tickers:
    thread = threading.Thread(target=fetch_data, args=(ticker,))
    threads.append(thread)
    thread.start()

  for thread in threads:
    thread.join() # 

if __name__ == "__main__":
  main()

