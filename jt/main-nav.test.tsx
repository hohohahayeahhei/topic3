import { render } from "@testing-library/react"
import '@testing-library/jest-dom/extend-expect'
import { MainNav } from "../main-nav"
import { BrowserRouter as Router } from 'react-router-dom'

describe("MainNav", () => {
  it("renders without crashing", () => {
    const { container } = render(
      <Router>
        <MainNav />
      </Router>
    )
    expect(container).toBeInTheDocument()
  })

  it("contains the Dashboard link", () => {
    const { getByText } = render(
      <Router>
        <MainNav />
      </Router>
    )
    expect(getByText("Dashboard")).toBeInTheDocument()
  })

  it("contains the Student Behavior link", () => {
    const { getByText } = render(
      <Router>
        <MainNav />
      </Router>
    )
    expect(getByText("Student Behavior")).toBeInTheDocument()
  })

  it("contains the Data Interaction link", () => {
    const { getByText } = render(
      <Router>
        <MainNav />
      </Router>
    )
    expect(getByText("Data Interaction")).toBeInTheDocument()
  })

  it("contains the Settings link", () => {
    const { getByText } = render(
      <Router>
        <MainNav />
      </Router>
    )
    expect(getByText("Settings")).toBeInTheDocument()
  })
})