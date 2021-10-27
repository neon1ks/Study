import json
from pprint import pprint
import http.client

HOST = 'localhost'

connection = http.client.HTTPConnection(HOST, port=8082)
connection.request('GET', '/')

response = connection.getresponse()

body = response.read().decode()
print('response is:', body)
