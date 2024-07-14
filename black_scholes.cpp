// black_scholes.cpp
#include <iostream>
#include <cmath>

double norm_pdf(const double& x) {
    return (1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * x * x);
}

double norm_cdf(const double& x) {
    return std::erfc(-x / std::sqrt(2)) / 2;
}

double d1(const double& S, const double& K, const double& r, const double& v, const double& T) {
    return (log(S / K) + (r + 0.5 * v * v) * T) / (v * sqrt(T));
}

double d2(const double& S, const double& K, const double& r, const double& v, const double& T) {
    return d1(S, K, r, v, T) - v * sqrt(T);
}

double call_option_price(const double& S, const double& K, const double& r, const double& v, const double& T) {
    return S * norm_cdf(d1(S, K, r, v, T)) - K * exp(-r * T) * norm_cdf(d2(S, K, r, v, T));
}

double put_option_price(const double& S, const double& K, const double& r, const double& v, const double& T) {
    return K * exp(-r * T) * norm_cdf(-d2(S, K, r, v, T)) - S * norm_cdf(-d1(S, K, r, v, T));
}

int main(int argc, char* argv[]) {
    if (argc != 7) {
        std::cerr << "Usage: " << argv[0] << " <S> <K> <r> <v> <T> <option_type>" << std::endl;
        return 1;
    }
    
    double S = std::stod(argv[1]);
    double K = std::stod(argv[2]);
    double r = std::stod(argv[3]);
    double v = std::stod(argv[4]);
    double T = std::stod(argv[5]);
    std::string option_type = argv[6];

    double price;
    if (option_type == "call") {
        price = call_option_price(S, K, r, v, T);
    } else if (option_type == "put") {
        price = put_option_price(S, K, r, v, T);
    } else {
        std::cerr << "Invalid option type. Use 'call' or 'put'." << std::endl;
        return 1;
    }

    std::cout << price << std::endl;

    return 0;
}
