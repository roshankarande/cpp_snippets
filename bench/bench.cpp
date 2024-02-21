#include<string>
#include<string_view>
#include<benchmark/benchmark.h>

void string_call(const std::string& s){}
void stringview_call(const std::string_view s){}

static void StringArgPass(benchmark::State& s){
    const char* str = "abcdefghijk";

    for (auto _ : s)
    {
        // std::string str1(str); 
        string_call(str);
    }
}
BENCHMARK(StringArgPass);

static void StringViewArgPass(benchmark::State& s){
    const char* str = "abcdefghijk";
    
    for (auto _ : s)
    {
        stringview_call(str);
    }
}
BENCHMARK(StringViewArgPass);

static void StringDecAssign(benchmark::State& s){
    const char* str = "abcdefghijk";

    for (auto _ : s)
    {
        std::string str1(str); 
    }
}
BENCHMARK(StringDecAssign);

static void StringViewDecAssign(benchmark::State& s){
    const char* str = "abcdefghijk";
    
    for (auto _ : s)
    {
        std::string_view str1(str); 
        // stringview_call(str);
    }
}
BENCHMARK(StringViewDecAssign);



static  void StringSubStr(benchmark::State& state) {
    std::string s = "Hello Super Extra Programming World";
    for (auto _ : state) {
        auto oneStr = s.substr(0, 5);
        auto twoStr = s.substr(6, 5);
        auto threeStr = s.substr(12, 5);
        auto fourStr = s.substr(18, 11);
        auto fiveStr = s.substr(30, 5);
        // Make sure the variable is not optimized away by compiler
        benchmark::DoNotOptimize(oneStr);
        benchmark::DoNotOptimize(twoStr);
        benchmark::DoNotOptimize(threeStr);
        benchmark::DoNotOptimize(fourStr);
        benchmark::DoNotOptimize(fiveStr);
    }
}
BENCHMARK(StringSubStr);

static void StringViewSubStr(benchmark::State& state) {
    // Code before the loop is not measured
    std::string s = "Hello Super Extra Programming World";
    for (auto _ : state) {
        std::string_view sv = s;
        auto oneSv = sv.substr(0, 5);
        auto twoSv = sv.substr(6, 5);
        auto threeSv = sv.substr(12, 5);
        auto fourSv = sv.substr(18, 11);
        auto fiveSv = sv.substr(30, 5);
        benchmark::DoNotOptimize(oneSv);
        benchmark::DoNotOptimize(twoSv);
        benchmark::DoNotOptimize(threeSv);
        benchmark::DoNotOptimize(fourSv);
        benchmark::DoNotOptimize(fiveSv);
    }
}
BENCHMARK(StringViewSubStr);

BENCHMARK_MAIN();

// Also substring operation is fast in string_view but split is slow.