import { render } from "@testing-library/react"
import '@testing-library/jest-dom'
import { AttendanceChart } from "../attendance-chart"

describe("AttendanceChart", () => {
  it("renders without crashing", () => {
    const { container } = render(<AttendanceChart />)
    expect(container).toBeInTheDocument()
  })

  it("renders the correct number of data points", () => {
    const { container } = render(<AttendanceChart />)
    const points = container.querySelectorAll(".recharts-line .recharts-line-curve")
    expect(points).toHaveLength(1) // Assuming there is one line in the chart
  })

  it("displays the correct data labels", () => {
    const { getByText } = render(<AttendanceChart />)
    expect(getByText("Week 1")).toBeInTheDocument()
    expect(getByText("Week 8")).toBeInTheDocument()
  })
})