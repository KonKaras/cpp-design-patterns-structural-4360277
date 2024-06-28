#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class WorldWeatherAPI
{
public:
    tuple<float, float, string> getWeather(string location)
    {
        cout << "Calling worldWeather with location: " << location << endl;
        float temperature = 20.0f;
        float windSpeed = 5.5f;
        string shortDescription = "Sunny";
        return make_tuple(temperature, windSpeed, shortDescription);
    }
};

class FreeWeather
{
public:
    tuple<float, string> retrieve_weather(string location)
    {
        cout << "Calling freeWeather with location: " << location << endl;
        float temperature = 22.0f;
        string shortDescription = "Sunny";
        return make_tuple(temperature, shortDescription);
    }
};

class RealtimeWeatherService
{
public:
    tuple<float, float, string> weatherConditions(string location)
    {
        cout << "Calling realtimeWeather with location: " << location << endl;
        float temperature = 19.5f;
        float humidity = 60.0f;
        string shortDescription = "Partly cloudy with a chance of rain";
        return make_tuple(temperature, humidity, shortDescription);
    }
};

class WeatherFacade {
    public:
        WeatherFacade(): worldWeather(), freeWeather(), realTimeWeatherService() {}
        string currentWeather(string location){
            const tuple<float, float, string> worldWeatherResult = worldWeather.getWeather(location);
            const tuple<float, string> freeWeatherResult = freeWeather.retrieve_weather(location);
            const tuple<float, float, string> realtimeWeatherResult = realTimeWeatherService.weatherConditions(location);

            const float temperature = get<0>(worldWeatherResult);
            const float humidity = get<1>(realtimeWeatherResult);
            const string shortDescription = get<1>(freeWeatherResult);

            stringstream result;
            result << "\nWeather for " << location << endl
                 << shortDescription << endl
                 << "Temperature: " << temperature << " C" << endl
                 << "Humidity: " << humidity << " %" << endl;
            return result.str();
        }
    private:
        WorldWeatherAPI worldWeather;
        FreeWeather freeWeather;
        RealtimeWeatherService realTimeWeatherService;

};

int main()
{
    WeatherFacade weatherFacade;
    auto const location = "San Francisco, CA, US";
    // Call each API and combine the results
    cout << weatherFacade.currentWeather(location); << endl;

    return 0;
}
