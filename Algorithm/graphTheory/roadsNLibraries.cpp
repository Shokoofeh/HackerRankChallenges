#include <bits/stdc++.h>

using namespace std;

class City
{
public:
    City () :
        m_num_cities (0),
        m_num_roads (0)
    { }

    City (size_t num_cities, size_t num_roads, long lib_cost, long road_cost)
        : m_num_cities(num_cities),
          m_num_roads(num_roads),
          m_lib_cost(lib_cast),
          m_road_cost(lib_cost)
    {
        std::vector<int> empty_vector;
        for (int i = 0; i < num_cities; ++i)
        {
            m_adj.push_back(empty_vector);
            m_cost.push_back(-1);
        }
    }

    ~City () { }
    void addEdge(int city_1, int city_2);
    int getTotalCost();

private:
    int     m_num_cities;
    int     m_num_roads;
    long    m_lib_cost;
    long    m_road_cost;
    int     m_total_cost;

    std::vector<std::vector<int>>   m_adj;
    std::vector<int>                m_cost;

};

void City::addEdge(int city_1, int city_2)
{
    m_adj[city_1].push_back(city_2);
    m_adj[city_2].push_back(city_1);
}

int City::getTotalCost()
{
    if (m_lib_cost <= m_road_cost)
    {
        return (m_num_cities * m_lib_cost);
    }
}

int main() {
    int q;
    cin >> q;
    for (int a0 = 0; a0 < q; a0++) {
        int n;
        int m;
        long x;
        long y;
        cin >> n >> m >> x >> y;

        City* city = new City (n, m, x, y);
        for (int a1 = 0; a1 < m; a1++) {
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            city->addEdge(city_1, city_2);
        }
    }
    return 0;
}

