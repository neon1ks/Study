from pprint import pprint
import requests

headers = {
    'Content-type': 'application/json',
}

data = {
    'MySecretHeader': 'spam and eggs',
    'what?' : 42,
}

# response = requests.request('GET', 'http://httpbin.org/get')
# response = requests.get('http://httpbin.org/get')
response = requests.post(
    'http://httpbin.org/post',
    headers=headers, json=data
)

# print(response)
# print(response.text)
# print(type(response.text))
pprint(response.json())

response_son = response.json()

pprint(response_son['json'] == data)
