import json
from pprint import pprint
import http.client

HOST = 'httpbin.org'

connection = http.client.HTTPConnection(HOST, port=80)
connection.request('GET', '/get')

response = connection.getresponse()

body = response.read().decode()
res = json.loads(body)
pprint(type(res))
pprint(res)

# print(type(body), body)
# print(response.status, response.reason)

print(repr(json.dumps(res['headers'])))
