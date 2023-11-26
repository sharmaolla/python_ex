1.

from flask import Flask, Response
import json

app = Flask(__name__)
@app.route('/prime_number/<number>')
def prime(number):
    number = int(number)
    count = 0
    checker = 1
    n = 0
    while checker <= number:
        if number % checker == 0:
            count += 1
        checker += 1
    else:
        checker += 1

    if count == 2:
        n = True
    else:
        n = False
    response = {
        "number": number,
        "isPrime": n,
    }
    json_response = json.dumps(response)
    http_response = Response(response=json_response, status=200, mimetype="application/json")
    return http_response

if __name__ == '__main__':
    app.run(use_reloader=True, host='127.0.0.1', port=5000)
