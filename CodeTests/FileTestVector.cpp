#include <iostream>
#include <vector>
#include <complex>
#include "../src/File.hpp"

using namespace std;
using namespace FilesApi;

int mainFileTestVector() {
    File f("../TestFiles/test_file.bin");
    vector<complex<float>> wdata = {{1, 9}, {3, 75}, {213.34, 21.4}, {153.1, 15.85}};
    vector<complex<float>> rdata(wdata.size());

    f.init_read_write_mode(ReadWriteMode::MULTIPLE, 2);
    f.write(wdata, wdata.size());
    f.write(wdata, wdata.size());
    f.init_read_write_mode(ReadWriteMode::MULTIPLE);
    f.read(rdata, rdata.size());
    f.read(rdata, rdata.size());

    for (size_t i = 0; i < rdata.size(); i++) {
        cout << rdata[i] << endl;
    }

    return 0;
}