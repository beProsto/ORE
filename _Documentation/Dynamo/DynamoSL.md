# Dynamo Shading Language
## Dynamo aspires to be an open source, easy to use shading language, that can be easily translated to any other shading language.
## Basics of syntax:
```cpp
#SHADER_TYPE VERTEX

uint8 convertFloatToByte(float32 _val) {
	return uint8(_val * 255.0);
}
float32 convertByteToFloat(uint8 _val) {
	return float32(_val) / 255.0;
}

vec4f main() {
	return u_ProjectionView * u_Model * vec4f(a_Position, 1.0f);
}
```
