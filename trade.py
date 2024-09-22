from alpaca.trading.client import TradingClient
from alpaca.trading.requests import GetAssetsRequest
from dotenv import load_dotenv
import os
load_dotenv()
# print(os.getenv('ALPACA_KEY'), os.getenv('ALPACA_KEY'))

trading_client = TradingClient(os.getenv('ALPACA_KEY'), os.getenv('ALPACA_SECRET'))

# Get our account information.
account = trading_client.get_account()

# Check if our account is restricted from trading.
if account.trading_blocked:
    print('Account is currently restricted from trading.')

# Check how much money we can use to open new positions.
print(account)