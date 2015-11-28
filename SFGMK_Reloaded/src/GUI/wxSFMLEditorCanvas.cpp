wxSFMLEditorCanvas::wxSFMLEditorCanvas(wxWindow* Parent, wxWindowID Id, const wxPoint& Position, const wxSize& Size, long Style)
	: wxSFMLCanvas(Parent, Id, Position, Size, Style)
{
	m_TextureGrid.loadFromFile("../data/editor/grid.png");

	m_SpriteGrid.setTexture(m_TextureGrid);

	m_Zoom = 1.0f;
}

wxSFMLEditorCanvas::~wxSFMLEditorCanvas()
{

}

void wxSFMLEditorCanvas::OnPaint(wxPaintEvent& _event)
{
	// On pr�pare le contr�le � �tre dessin�
	wxPaintDC dc(this);

	// On efface la vue
	clear(sf::Color(128, 128, 128));

	// Pre loop
	m_InputManager->update();

	// On laisse la classe d�riv�e se mettre � jour et dessiner dans le contr�le
	OnUpdate();

	// On affiche tout �a � l'�cran
	display();
}

void wxSFMLEditorCanvas::OnEditionBasicDragPos()
{
	MyGUI* gui = MyGUI::GetGUI();

	GameObject *gameobject = gui->selectedGameObject;

	if (gameobject)
	{
		sfgmk::Mouse& mouse = m_InputManager->getMouse();

		int state = mouse.getButtonState(sf::Mouse::Left);

		if (state == KEY_PRESSED)
		{
			m_BasicDragPosMouseBegin = mouse.getWorldPosition();
			m_BasicDragPosTransformBegin = gameobject->transform.position;
		}
		else if (state == KEY_DOWN)
		{
			sf::Vector2f diff = mouse.getWorldPosition() - m_BasicDragPosMouseBegin;
			gameobject->transform.position = m_BasicDragPosTransformBegin + diff;

			gui->Update_PropertyGrid();
		}
	}
}

void wxSFMLEditorCanvas::OnEditionBasicDragCamera()
{
	sf::View view = getView();

	sfgmk::Mouse& mouse = m_InputManager->getMouse();

	int state = mouse.getButtonState(sf::Mouse::Middle);

	if (state == KEY_PRESSED)
	{
		m_BasicDragPosMouseBegin = sf::Vector2f(mouse.getWindowPosition());
		m_BasicDragPosCameraBegin = view.getCenter();
	}
	else if (state == KEY_DOWN)
	{
		sf::Vector2f diff = sf::Vector2f(mouse.getWindowPosition()) - m_BasicDragPosMouseBegin;

		view.setCenter(m_BasicDragPosCameraBegin - diff);
		setView(view);
	}
}

void wxSFMLEditorCanvas::OnEditionBasicZoomCamera()
{
	sf::View view = getView();

	sfgmk::Mouse& mouse = m_InputManager->getMouse();

	int tick = mouse.getWheelState();

	if (tick)
	{
		m_Zoom -= tick * 0.1f;

		if (m_Zoom <= 0.0f)
			m_Zoom = 0.1f;

		view.setSize(SFGMKR_DEFAULT_SFML_SIZE_X * m_Zoom, SFGMKR_DEFAULT_SFML_SIZE_Y * m_Zoom);
		setView(view);
	}
}

void wxSFMLEditorCanvas::OnEditionDrawGrid()
{
	for (int x = -1; x < 6; x++)
	{
		for (int y = -1; y < 4; y++)
		{
			m_SpriteGrid.setPosition(x * 256.0f, y * 256.0f);
			draw(m_SpriteGrid);
		}
	}
}

void wxSFMLEditorCanvas::OnUpdate()
{
	OnEditionBasicDragPos();
	OnEditionBasicDragCamera();
	OnEditionBasicZoomCamera();

	OnEditionDrawGrid();

	sfgmk::vector<GameObject*>& gameobjects = GameObjectManager::GetSingleton()->getGameObjects();

	for (unsigned int i = 0; i < gameobjects.getElementNumber(); i++)
		gameobjects[i]->draw(this);
}