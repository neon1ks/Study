#include "iconeditorplugin.h"
#include "iconeditor.h"

#include <QtPlugin>

IconEditorPlugin::IconEditorPlugin(QObject *parent)
    : QObject(parent)
{
	m_initialized = false;
}

void IconEditorPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
	if (m_initialized)
		return;

	// Add extension registrations, etc. here

	m_initialized = true;
}

auto IconEditorPlugin::isInitialized() const -> bool
{
	return m_initialized;
}

auto IconEditorPlugin::createWidget(QWidget *parent) -> QWidget *
{
	return new IconEditor(parent);
}

auto IconEditorPlugin::name() const -> QString
{
	return QLatin1String("IconEditor");
}

auto IconEditorPlugin::group() const -> QString
{
	return QLatin1String("Image Manipulation Widgets");
}

auto IconEditorPlugin::icon() const -> QIcon
{
	return QIcon(":/images/iconeditor.png");
}

auto IconEditorPlugin::toolTip() const -> QString
{
	return QLatin1String("An icon editor widget");
}

auto IconEditorPlugin::whatsThis() const -> QString
{
	return QLatin1String("This widget is presented in Chapter 5 of <i>C++ GUI "
	                     "Programming with Qt 4</i> as an example of a custom Qt "
	                     "widget.");
}

auto IconEditorPlugin::isContainer() const -> bool
{
	return false;
}

auto IconEditorPlugin::domXml() const -> QString
{
	return QLatin1String("<widget class=\"IconEditor\" name=\"iconEditor\">\n</widget>\n");
}

auto IconEditorPlugin::includeFile() const -> QString
{
	return QLatin1String("iconeditor.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(iconeditorplugin, IconEditorPlugin)
#endif  // QT_VERSION < 0x050000
