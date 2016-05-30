#include <vector>
#include <limits>
#include <string>
#include <sstream>

namespace cmst
{
    class Stat
    {
    public:
        Stat() : m_min(std::numeric_limits<double>::max()), m_max(std::numeric_limits<double>::min()) {}

        void record(double data)
        {
            m_data.push_back(data);
            m_min = std::min(m_min, data);
            m_max = std::max(m_max, data);
        }

        double min() const { return m_min; }

        double max() const { return m_max; }

        int count() const { return m_data.size(); }

        double mean()
        {
            int n = m_data.size();
            m_mean = 0.0;
            for (int i = 0; i < n; i++)
                m_mean += m_data[i];
            return m_mean = m_mean / n;
        }

        double standardDeviation()
        {
            mean();
            m_standardDeviation = 0.0;
            int n = m_data.size();
            for (int i = 0; i < n; i++)
                m_standardDeviation += (m_data[i] - m_mean) * (m_data[i] - m_mean);
            return m_standardDeviation = std::sqrt(m_standardDeviation);
        }

        std::string print()
        {
            std::stringstream str;
            mean();
            standardDeviation();
            str << "*** Average: " << m_min << std::endl;
            str << "*** Maximum: " << m_max << std::endl;
            str << "*** Minimum: " << m_min << std::endl;
            str << "*** Standard Deviation: " << m_standardDeviation;

            return str.str();
        }

    private:

        double m_min;
        double m_max;
        double m_mean;
        double m_standardDeviation;
        std::vector<double> m_data;
    };
}
