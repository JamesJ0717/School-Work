import requests
import time


# while(True):
f = open('rvnBalance.txt', 'a')
r = requests.get(
    'https://miningpanda.site/api/wallet?address=RHzDtA9VCVEhMAkezvyXWL4W7ifXxcPkQq')
localTime = str(time.asctime())
f.write(localTime)
print(localTime)
f.write(r.text)
print(r.text)
f.write('\n')
f.close()
# time.sleep(3600)
