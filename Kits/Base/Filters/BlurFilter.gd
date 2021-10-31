extends Actor
class_name BlurFilter

export(float, 0.0, 10.0) var blur_amount : float


func _ready():
	set_blur(blur_amount)


func set_blur(blur : float):
	blur_amount = blur
	material.set_shader_param("blur", blur)
