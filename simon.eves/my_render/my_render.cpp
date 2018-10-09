#include <mbgl/map/map.hpp>
#include <mbgl/util/image.hpp>
#include <mbgl/util/run_loop.hpp>
#include <mbgl/util/default_styles.hpp>
#include <mbgl/util/default_thread_pool.hpp>
#include <mbgl/gl/headless_frontend.hpp>
#include <mbgl/storage/default_file_source.hpp>
#include <mbgl/style/style.hpp>

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace mbgl;

int main(int argc, char *argv[]) {

    std::string style = util::default_styles::streets.url;
    const double lat = 0.0;
    const double lon = 0.0;
    const double zoom = 2.0;
    const double bearing = 0.0;
    const double pitch = 0.0;
    const double pixelRatio = 1.0;
    const uint32_t width = 1024;
    const uint32_t height = 1024;
    const std::string output = "out.png";
    const std::string cache_file = "cache.sqlite";
    const std::string asset_root = ".";
    const std::string token = getenv("MAPBOX_ACCESS_TOKEN");
    const bool debug = false;

    util::RunLoop loop; // not referenced in code below but one has to be constructed otherwise you get a static assert!

    DefaultFileSource fileSource(cache_file, asset_root);
    fileSource.setAccessToken(token);

    ThreadPool threadPool(4);

    HeadlessFrontend frontend({ width, height }, pixelRatio, fileSource, threadPool);

    Map map(frontend, MapObserver::nullObserver(), frontend.getSize(), pixelRatio, fileSource, threadPool, MapMode::Static);
    map.getStyle().loadURL(style);
    map.setLatLngZoom({ lat, lon }, zoom);
    map.setBearing(bearing);
    map.setPitch(pitch);

    try {
        std::ofstream out(output, std::ios::binary);
        out << encodePNG(frontend.render(map));
        out.close();
    } catch(std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        exit(1);
    }

    return 0;
}
