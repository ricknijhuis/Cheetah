#include "UpdateLayerQueue.h"

namespace cheetah
{

	UpdateLayerQueue::UpdateLayerQueue()
	{
		m_layerInsertPos = m_layerQueue.begin();
	}

	UpdateLayerQueue::~UpdateLayerQueue()
	{
		for (UpdateLayer* layer : m_layerQueue)
		{
			delete layer;
		}
	}

	void UpdateLayerQueue::pushLayer(UpdateLayer* layer)
	{
		m_layerInsertPos = m_layerQueue.emplace(m_layerInsertPos, layer);
		layer->onAttach();
	}

	void UpdateLayerQueue::pushOverlay(UpdateLayer* overlay)
	{
		m_layerQueue.emplace_back(overlay);
		overlay->onAttach();
	}

	void UpdateLayerQueue::popLayer(UpdateLayer* layer)
	{
		auto it = std::find(m_layerQueue.begin(), m_layerQueue.end(), layer);
		if (it != m_layerQueue.end())
		{
			layer->onDetach();
			m_layerQueue.erase(it);
			m_layerInsertPos--;
		}
	}

	void UpdateLayerQueue::popOverlay(UpdateLayer* overlay)
	{
		auto it = std::find(m_layerQueue.begin(), m_layerQueue.end(), overlay);
		if (it != m_layerQueue.end())
		{
			overlay->onDetach();
			m_layerQueue.erase(it);
		}
	}

	void UpdateLayerQueue::onUpdate(const float& deltaTime)
	{
		for (UpdateLayer* layer : m_layerQueue)
			layer->onUpdate(deltaTime);
	}

	std::vector<UpdateLayer*>::iterator UpdateLayerQueue::begin()
	{
		return m_layerQueue.begin();
	}

	std::vector<UpdateLayer*>::iterator UpdateLayerQueue::end()
	{
		return m_layerQueue.end();
	}

	std::vector<UpdateLayer*>::reverse_iterator UpdateLayerQueue::rbegin()
	{
		return m_layerQueue.rbegin();
	}

	std::vector<UpdateLayer*>::reverse_iterator UpdateLayerQueue::rend()
	{
		return m_layerQueue.rend();
	}
}
