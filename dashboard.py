import streamlit as st
import pandas as pd

st.title('My first app!')

st.write("Text input widget:")
# Text input widget
name = st.text_input('Enter your name:', '')

# Display the name
if name:
    st.write(f'Hello, {name}!')

st.write("This is a slider widget: ")
#Slider widget
age = st.slider('Select your age:', 0, 100, 5)
st.write(f'Your age is: {age}')

df = pd.DataFrame({
    'name': ['John', 'Jane', 'Joe'],
    'age': [25, 30, 35]
})

st.write("This is a checkbox widget: ")
#Checkbox widget
if st.checkbox('Show dataframe'):
    st.write(df)

#Radio buttons
favorite_color = st.radio('Select your favorite color:', ('Blue', 'Red', 'Green'))
st.write(f'Your favorite color is: {favorite_color}')