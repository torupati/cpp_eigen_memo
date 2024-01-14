#include <iostream>
#include <fstream>
#include <Eigen/Dense>

void load_from_memory(Eigen::MatrixXf& p)
{
    for(Eigen::Index i=0; i< p.rows(); i++){
        for(Eigen::Index j=0; j<p.cols(); j++){
            p(i, j) = 2.0;
        }
    }
}

void save_csvfile(const std::string& filename, const Eigen::MatrixXf&  matrix)
{
    //https://eigen.tuxfamily.org/dox/structEigen_1_1IOFormat.html
    const static Eigen::IOFormat CSVFormat(Eigen::FullPrecision, Eigen::DontAlignCols, ",", "\n");
    std::ofstream f(filename);
    if(f.is_open())
    {
        f << matrix.format(CSVFormat);
        f.close();
    }else{
        // todo: throw exception?
    }
}

int read_values_from_csvfile(const std::string& file, Eigen::MatrixXf& mat) {
    std::ifstream f(file);
    if (f.is_open()) {
        int row = 0;
        std::string line;
        while (std::getline(f, line)) {
            const char *ptr = line.c_str();
            int col = 0;
            const char *start = ptr;
            for (int i = 0; i < static_cast<int>(line.length()); i++) {
                if (ptr[i] == ',') {
                    mat(row, col++) = atof(start);
                    start = ptr + i + 1;
                }
            }
            mat(row, col) = atof(start);
            row++;
        }
        f.close();
    }else{
        return -1;
    }
    return 0;
}

int main()
{
    Eigen::MatrixXf coef(41,8);
    load_from_memory(coef);
    std::cout << "rows=" << coef.rows() << std::endl;
    save_csvfile("out1.csv", coef);
    coef = Eigen::MatrixXf::Random(coef.rows(), coef.cols());
    save_csvfile("out2.csv", coef);

    Eigen::MatrixXf mat(coef.rows(), coef.cols());
    read_values_from_csvfile("out2.csv", mat);
    save_csvfile("out3.csv", coef);

    Eigen::MatrixXf src(1080*1920, 8);
    std::cout << "defined src(" << (1080*1920) << ",8)" << std::endl;
    Eigen::MatrixXf b = Eigen::MatrixXf::Random(8, 50);
    Eigen::MatrixXf y(1080*1920, 50);
    std::cout << "aiueo" << std::endl;
    y = src * b;
    std::cout << "multiplication done" << std::endl;
    std::cout << y.cols() << ", " << y.rows() << std::endl;

    //std::cout << coef << std::endl;
}
