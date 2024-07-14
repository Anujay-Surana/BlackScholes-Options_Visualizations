# app.py
from flask import Flask, request, jsonify, render_template
import subprocess

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/calculate', methods=['POST'])
def calculate():
    data = request.json
    S = data['S']
    K = data['K']
    r = data['r']
    v = data['v']
    T = data['T']
    option_type = data['option_type']

    result = subprocess.run(['./black_scholes', str(S), str(K), str(r), str(v), str(T), option_type], capture_output=True, text=True)
    price = result.stdout.strip()
    return jsonify({'price': price})

if __name__ == '__main__':
    app.run(debug=True)
