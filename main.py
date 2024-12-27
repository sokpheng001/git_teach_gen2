from fastapi import FastAPI

app = FastAPI()

@app.get("/api/v1/{product_name}")
async def create_user(product_name: str):
    return {"message": f"Product '{product_name}' created successfully"}