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

2.
'''
Implement a backend service that gets the ICAO code of an airport and then returns the name and location
 of the airport in JSON format. The information is fetched from the airport database used on this course.
  For example, the GET request for EFHK would be: http://127.0.0.1:5000/airport/EFHK. Th
  e response must be in the format of: {"ICAO":"EFHK", "Name":"Helsinki-Vantaa Airport", "Location":"Helsinki"}.
'''
(PARTIALLY DONE)
import mysql.connector


connection = mysql.connector.connect(
         host='127.0.0.1',
         port=3306,
         database='flight_game',
         user='dbuser',
         password='sha******',
         autocommit=True
         )

request = "SELECT ident,name, municipality FROM airport WHERE id = 2307"
cursor = connection.cursor()
cursor.execute(request)
response = cursor.fetchall()
print(response)



