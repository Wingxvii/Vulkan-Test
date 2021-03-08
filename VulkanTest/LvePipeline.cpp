#include "LvePipeline.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace lve {

	lve::LvePipeline::LvePipeline(const std::string& vertPath, const std::string& fragPath)
	{
		createGraphicsPipeline(vertPath, fragPath);

	}

	std::vector<char> lve::LvePipeline::readFile(const std::string& filepath)
	{
		std::ifstream file{ filepath, std::ios::ate | std::ios::binary};

		if (!file.is_open()) {
			throw std::runtime_error("failed to open file:" + filepath);
		}

		size_t filesize = static_cast<size_t>(file.tellg());

		std::vector<char> buffer(filesize);

		file.seekg(0);
		file.read(buffer.data(), filesize);
		file.close();

		return buffer;
	}

	void lve::LvePipeline::createGraphicsPipeline(const std::string& vertPath, const std::string& fragPath)
	{
		auto vertCode = readFile(vertPath);
		auto fragCode = readFile(fragPath);

		std::cout << "Vertex shader Code Size: " << vertCode.size() << '\n';
		std::cout << "Fragment shader Code Size: " << fragCode.size() << '\n';
	}
}