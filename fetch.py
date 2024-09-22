"""
sumarry
"""
import threading
import yfinance as yf
import time
import json
import os

SLEEP_TIME = 60

# download stock data using yfinance API
def make_api_call(ticker):
  try:
    data = yf.download(tickers=ticker, interval="1m", period="1d")
    return data
  except Exception as e:
    print(f'error with API: {e}')
    return None

# save in CSV format
def save_to_json(data, filename):
  if data is not None:
    data.to_csv(filename, index=True)

# fetch data every minue
def fetch_data(ticker):
  while True:
    data = make_api_call(ticker)
    save_to_json(data, f'{ticker}.csv')
    print(f'wrote to file for {ticker}')
    time.sleep(SLEEP_TIME)

def main():
  tickers = ['AAPL', 'MSFT']
  threads = []
  # create threads to concurrently grab data
  for ticker in tickers:
    thread = threading.Thread(target=fetch_data, args=(ticker,))
    threads.append(thread)
    thread.start()

  for thread in threads:
    thread.join() # wait for child threads before exiting main

if __name__ == "__main__":
  main()

