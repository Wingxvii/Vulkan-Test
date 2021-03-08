#include "LvePipeline.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace lve {

	lve::LvePipeline::LvePipeline(LveDevice& device, const std::string& vertPath, const std::string& fragPath, const PipelineConfigInfo& configInfo) :lveDevice{device}
	{
		createGraphicsPipeline(vertPath, fragPath, configInfo);

	}

	PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(int32_t width, uint32_t height)
	{
		PipelineConfigInfo configInfo{};

		return configInfo;
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

	void lve::LvePipeline::createGraphicsPipeline(const std::string& vertPath, const std::string& fragPath, const PipelineConfigInfo& configInfo)
	{
		auto vertCode = readFile(vertPath);
		auto fragCode = readFile(fragPath);

		std::cout << "Vertex shader Code Size: " << vertCode.size() << '\n';
		std::cout << "Fragment shader Code Size: " << fragCode.size() << '\n';
	}

	void LvePipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule)
	{
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

		if (vkCreateShaderModule(lveDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create shader module");
		}
	}

}