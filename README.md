# BlackScholes-Options_Visualizations

This project is a web application that calculates option prices using the Black-Scholes model. It supports both call and put options and uses a C++ backend for the calculations and a Python/Flask server for handling requests and rendering the frontend. The frontend uses Chart.js for data visualization.

## Features

- Calculate call and put option prices using the Black-Scholes model
- Simple and clean user interface
- Visualize option parameters with Chart.js

## Technologies Used

- C++ for backend calculations
- Python and Flask for the web server
- HTML, CSS, JavaScript for the frontend
- Chart.js for charting and data visualization

## Requirements

- g++ (GCC) for compiling the C++ code
- Python 3.x and Flask
- Web browser

## Installation

### 1. Clone the repository

```sh
git clone https://github.com/your-username/black-scholes-web-app.git
cd black-scholes-web-app
```

### 2. Compile the C++ program

```sh
g++ -o black_scholes black_scholes.cpp -lm
```

### 3. Install Flask

```sh
pip install flask
```

### 4. Run the Flask app

```sh
python app.py
```

### 5. Open your browser

Go to `http://127.0.0.1:5000/` to access the application.

## Usage

1. Enter the following parameters:
   - Stock Price (S)
   - Strike Price (K)
   - Risk-Free Rate (r)
   - Volatility (v)
   - Time to Maturity (T)
   - Option Type (call or put)
2. Click the "Calculate" button to compute the option price.
3. The option price will be displayed, and a chart will visualize the parameters.

## Contributing

Feel free to fork this repository and submit pull requests. For major changes, please open an issue first to discuss what you would like to change.

## License

This project is licensed under the MIT License.
