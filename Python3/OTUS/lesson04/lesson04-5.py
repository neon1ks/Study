import json
from pprint import pprint
import http.client

HOST = 'httpbin.org'

connection = http.client.HTTPConnection(HOST, port=80)

connection.request('POST', '/post')
response = connection.getresponse()
# body = response.read().decode()
# print(body)
data = json.loads(response.read().decode())
pprint(data)

