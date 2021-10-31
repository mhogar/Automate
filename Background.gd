extends TextureRect

export var scroll : Vector2 = Vector2(0.0, 0.0)
export(Color) var color1 : Color
export(Color) var color2 : Color


func _ready():
	material.set_shader_param("scroll", scroll)
	material.set_shader_param("color1", color1)
	material.set_shader_param("color2", color2)
