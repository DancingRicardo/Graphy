#pragma once
#include "TaskWrapper.hpp"
#include "okapi/api/units/QTime.hpp"
#include "pros/screen.hpp"
#include <map>
#include <string>

#define MAX_CACHE_SIZE 430
#define GRAPH_TOP 40
#define GRAPH_BOTTOM 215
#define GRAPH_LEFT 25
#define GRAPH_RIGHT 455

class AsyncGrapher : public TaskWrapper {
    private: 
    std::map<std::string, std::vector<double>> container;
    std::map<std::string, uint32_t> colors;
    std::string title;
    okapi::QTime refreshRate;

    public: 
    /**
     * @brief Construct a new Async Grapher object
     * 
     * @param title graph title
     * @param rate refresh rate (default 10 ms)
     */
    AsyncGrapher(const std::string &title, const okapi::QTime &rate = 10 * okapi::millisecond);

    /**
     * @brief Add new data type
     * 
     * @param name data name
     * @param color line color
     */
    void addDataType(const std::string &name, const uint32_t color);

    /**
     * @brief Update graph with new value
     * 
     * @param name data name
     * @param val updated value
     */
    void update(const std::string &name, double val);

    /**
     * @brief Set the Refresh Rate 
     * 
     * @param rate refresh rate 
     */
    void setRefreshRate(const okapi::QTime &rate);

    /**
     * @brief Get the current refresh rate
     * 
     * @return refresh rate
     */
    okapi::QTime getRefreshRate();

    protected:
    void loop() override;
};